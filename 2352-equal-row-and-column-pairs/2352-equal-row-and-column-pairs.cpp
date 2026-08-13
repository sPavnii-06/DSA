class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> map;
        for(int i=0;i<n;i++){
            map[grid[i]]++;
        }
        int pair_count=0;
        for(int i=0; i<n; i++){
            vector<int> cur_col;
            for(int j=0; j<n; j++){
                cur_col.push_back(grid[j][i]);
            }
            if(map.find(cur_col)!=map.end()){
                pair_count+=map[cur_col];
            }
        }
        return pair_count;
        
        
    }
};