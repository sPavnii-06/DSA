class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n=nums.size();
        int min=*min_element(nums.begin(),nums.end());
        int max=*max_element(nums.begin(),nums.end());

        unordered_set<int>present(nums.begin(),nums.end());
        vector<int>missing;

        for(int i=min;i<=max;i++){
            if(present.find(i)==present.end()){
                missing.push_back(i);
            }
            
        }
        return missing;
        


    }
};