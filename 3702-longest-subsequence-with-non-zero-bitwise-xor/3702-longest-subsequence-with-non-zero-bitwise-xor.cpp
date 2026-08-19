class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        for (int x : nums) totalXor ^= x;
        int n = nums.size();
        
        if (totalXor != 0) return n;
        bool allZero = true;
        for (int x : nums) {
            if (x != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) return 0;
        return n - 1;
    }
};