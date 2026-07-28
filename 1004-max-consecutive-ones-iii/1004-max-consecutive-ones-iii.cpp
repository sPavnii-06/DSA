class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0;
        int Zeros_count=0;
        int n=nums.size();
        int max_len=0;

        
        while(right<n){
            if(nums[right]==0) Zeros_count++;
            while(Zeros_count >k){
                if(nums[left]==0)Zeros_count--;
                left++;

            }

            int cur_len=right-left+1;
            max_len=max(max_len,cur_len);
            right++;


        }
        return max_len;
        
        
    }
};