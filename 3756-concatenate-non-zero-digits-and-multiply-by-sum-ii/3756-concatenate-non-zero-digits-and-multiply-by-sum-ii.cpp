class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = s.size();
        
        
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        
        vector<int> sumD(n + 1, 0), cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';
            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);
            p[i] = d ? (p[i - 1] * 10 + d) % MOD : p[i - 1];
        }
        
        vector<int> answer(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            int n0 = cntN0[r + 1] - cntN0[l]; 
            int sum = sumD[r + 1] - sumD[l];  
            
            long long x = (p[r + 1] - (p[l] * pow10[n0]) % MOD + MOD) % MOD;
            
            answer[i] = (x * sum) % MOD;
        }
        
        return answer;
    }
};
