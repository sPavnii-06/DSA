class Solution {
    struct Interval {
        long long l, r, w;
        int idx;
        bool operator<(const Interval& other) const {
            return r < other.r;
        }
    };

    struct Result {
        long long sum = 0;
        vector<int> indices;
        
        bool better(const Result& other) const {
            if (sum != other.sum) return sum > other.sum;
            return indices < other.indices; 
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& rawIntervals) {
        int n = rawIntervals.size();
        vector<Interval> intervals(n);
        for (int i = 0; i < n; ++i) {
            intervals[i] = {rawIntervals[i][0], rawIntervals[i][1], rawIntervals[i][2], i};
        }
        
        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });
        vector<int> prev_idx(n, -1);
        vector<long long> ends(n);
        for (int i = 0; i < n; ++i) ends[i] = intervals[i].r;

        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(ends.begin(), ends.begin() + i, intervals[i].l);
            if (it != ends.begin()) {
                prev_idx[i] = distance(ends.begin(), it) - 1;
            }
        }
        vector<vector<Result>> dp(n + 1, vector<Result>(5));

        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= 4; ++k) {
                dp[i][k] = dp[i - 1][k];
            }

            const auto& cur = intervals[i - 1];
            for (int k = 1; k <= 4; ++k) {
                Result pick;
                pick.sum = cur.w;
                pick.indices = {cur.idx};

                int p = prev_idx[i - 1];
                if (p != -1) {
                    pick.sum += dp[p + 1][k - 1].sum;
                    pick.indices.insert(pick.indices.begin(), 
                                        dp[p + 1][k - 1].indices.begin(), 
                                        dp[p + 1][k - 1].indices.end());
                    sort(pick.indices.begin(), pick.indices.end());
                }

                if (pick.better(dp[i][k])) {
                    dp[i][k] = pick;
                }
            }
        }
        Result best_res;
        for (int k = 0; k <= 4; ++k) {
            if (dp[n][k].better(best_res)) {
                best_res = dp[n][k];
            }
        }

        return best_res.indices;
    }
};
