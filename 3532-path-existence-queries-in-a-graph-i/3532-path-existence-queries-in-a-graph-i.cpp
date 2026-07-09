class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<int> component(n, 0);
        
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                component[i] = component[i - 1];
            } else {
                component[i] = component[i - 1] + 1;
            }
        }
        
        
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            answer.push_back(component[u] == component[v]);
        }
        
        return answer;
    }
};
