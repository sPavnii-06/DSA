class Solution {
public:
    int maxDepth(string s) {
        int max_depth=0;
        int curr_depth =0;
        for (char c:s){
            if(c =='('){
                max_depth = max(max_depth, ++curr_depth);
            } else if (c == ')'){
                curr_depth--;
            }
        }
        return max_depth;
        
    }
};