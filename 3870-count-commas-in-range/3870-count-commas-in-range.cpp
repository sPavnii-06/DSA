class Solution {
public:
    int countCommas(int n) {
        long long total_commas = 0;
        if (n >= 1000) {
            total_commas += (n - 1000 + 1);
        }
        if (n >= 1000000) {
            total_commas += (n - 1000000 + 1);
        }
        if (n >= 1000000000) {
            total_commas += (n - 1000000000 + 1);
        }
        
        return static_cast<int>(total_commas);
    }
};