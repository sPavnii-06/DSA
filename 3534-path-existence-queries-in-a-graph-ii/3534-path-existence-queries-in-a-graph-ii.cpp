class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Step 1: Pair each value with its original index and sort by value
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }
        sort(pairs.begin(), pairs.end());

        // Step 2: Map original index to its position in the sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[pairs[i].second] = i;
        }

        // Step 3: Compute the farthest index reachable within maxDiff in 1 step
        int m = 18; // 2^17 > 10^5, sufficient for constraints
        vector<vector<int>> f(n, vector<int>(m));
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && pairs[j].first - pairs[i].first <= maxDiff) {
                j++;
            }
            f[i][0] = j - 1; // Farthest element reachable in 2^0 = 1 jump
        }

        // Step 4: Construct the binary lifting table
        for (int k = 1; k < m; k++) {
            for (int i = 0; i < n; i++) {
                f[i][k] = f[f[i][k - 1]][k - 1];
            }
        }

        // Step 5: Process each query using binary lifting
        int q = queries.size();
        vector<int> ans(q);
        for (int t = 0; t < q; t++) {
            int i = pos[queries[t][0]];
            int j = pos[queries[t][1]];

            // Ensure i is always to the left of j in sorted order
            if (i > j) {
                swap(i, j);
            }

            if (i == j) {
                ans[t] = 0;
                continue;
            }

            int steps = 0;
            // Greedily lift 'i' as far right as possible without passing or hitting 'j'
            for (int k = m - 1; k >= 0; k--) {
                if (f[i][k] < j) {
                    steps |= (1 << k);
                    i = f[i][k];
                }
            }

            // Check if one final hop can cover or cross the distance to 'j'
            if (f[i][0] >= j) {
                ans[t] = steps + 1;
            } else {
                ans[t] = -1; // Elements belong to disconnected components
            }
        }

        return ans;
    }
};
