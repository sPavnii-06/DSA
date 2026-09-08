class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        int total = 0;
        int dp[26]{};
        for(char& c : s){
            c-= 'a';

            int add = (total -dp[c] + MOD) % MOD;
            dp[c]= 1+total;
            total = (dp[c]+ add)% MOD;
        }
        return total;
    }
};