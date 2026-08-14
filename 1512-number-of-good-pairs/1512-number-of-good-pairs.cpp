class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        int count = 0;
        
        for (int x : nums) {
            count += freq[x];
            freq[x]++;
        }
        
        return count;
    }
};