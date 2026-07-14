class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }
        
        int MOD = 1e9 + 7;
        // dp[g1][g2] stores the number of pairs of disjoint subsequences 
        // with a current GCD of g1 for the first and g2 for the second.
        // 0 represents an empty subsequence since gcd(0, x) = x.
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1; 
        
        for (int x : nums) {
            vector<vector<int>> next_dp = dp;
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    
                    // Option 1: Add x to the first subsequence
                    int ng1 = std::gcd(g1, x);
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;
                    
                    // Option 2: Add x to the second subsequence
                    int ng2 = std::gcd(g2, x);
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        
        long long total_pairs = 0;
        for (int g = 1; g <= max_val; ++g) {
            total_pairs = (total_pairs + dp[g][g]) % MOD;
        }
        
        return total_pairs;
    }
};
