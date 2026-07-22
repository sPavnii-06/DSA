class Solution {
    struct OneBlock {
        int o_start, o_end;
        int l_start, r_end;
        int const_gain;
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // 1. Total '1's in the entire string
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        // 2. Identify all contiguous blocks of '1's
        vector<pair<int, int>> initial_blocks;
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') i++;
                initial_blocks.push_back({start, i - 1});
            } else {
                i++;
            }
        }
        
        // 3. Filter valid internal blocks (surrounded by '0's) and precompute boundary zero blocks
        vector<OneBlock> blocks;
        for (auto& p : initial_blocks) {
            int o_start = p.first;
            int o_end = p.second;
            
            // If it touches the absolute boundary of s, it can never be surrounded by '0's in the augmented string
            if (o_start == 0 || o_end == n - 1) continue;
            
            int l_start = o_start - 1;
            while (l_start > 0 && s[l_start - 1] == '0') l_start--;
            
            int r_end = o_end + 1;
            while (r_end < n - 1 && s[r_end + 1] == '0') r_end++;
            
            int const_gain = (o_start - l_start) + (r_end - o_end);
            blocks.push_back({o_start, o_end, l_start, r_end, const_gain});
        }
        
        int m_blocks = blocks.size();
        vector<int> o_start_arr(m_blocks), o_end_arr(m_blocks);
        for (int j = 0; j < m_blocks; ++j) {
            o_start_arr[j] = blocks[j].o_start;
            o_end_arr[j] = blocks[j].o_end;
        }
        
        // 4. Build a Sparse Table for O(1) Range Maximum Queries (RMQ)
        int max_log = m_blocks > 0 ? log2(m_blocks) + 1 : 1;
        vector<vector<int>> st(m_blocks, vector<int>(max_log, 0));
        for (int j = 0; j < m_blocks; ++j) {
            st[j][0] = blocks[j].const_gain;
        }
        for (int k = 1; k < max_log; ++k) {
            for (int j = 0; j + (1 << k) <= m_blocks; ++j) {
                st[j][k] = max(st[j][k - 1], st[j + (1 << (k - 1))][k - 1]);
            }
        }
        
        auto query_st = [&](int L, int R) {
            if (L > R) return 0;
            int len = R - L + 1;
            int k = log2(len);
            return max(st[L][k], st[R - (1 << k) + 1][k]);
        };
        
        // Lambda to compute dynamically truncated gain for edge blocks
        auto compute_gain = [&](int idx, int l, int r) {
            return (blocks[idx].o_start - max(blocks[idx].l_start, l)) + 
                   (min(blocks[idx].r_end, r) - blocks[idx].o_end);
        };
        
        // 5. Process each query independently
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            
            // A '1' block is completely within [l, r] and surrounded by '0's inside the window if:
            // o_start >= l + 1  AND  o_end <= r - 1
            int start_idx = lower_bound(o_start_arr.begin(), o_start_arr.end(), l + 1) - o_start_arr.begin();
            int end_idx = upper_bound(o_end_arr.begin(), o_end_arr.end(), r - 1) - o_end_arr.begin() - 1;
            
            int max_gain = 0;
            if (start_idx <= end_idx) {
                if (start_idx == end_idx) {
                    max_gain = compute_gain(start_idx, l, r);
                } else {
                    // Check clipped values at the boundary indices
                    max_gain = max(compute_gain(start_idx, l, r), compute_gain(end_idx, l, r));
                    // Check unclipped full constant gains for internal blocks
                    if (start_idx + 1 <= end_idx - 1) {
                        max_gain = max(max_gain, query_st(start_idx + 1, end_idx - 1));
                    }
                }
            }
            
            ans.push_back(total_ones + max_gain);
        }
        
        return ans;
    }
};
