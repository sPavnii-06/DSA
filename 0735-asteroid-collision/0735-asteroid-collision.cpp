class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>my_st;
        int n=asteroids.size();
        for(int i:asteroids){
            bool destroy_cur=false;
            while(!my_st.empty() && my_st.top()>0 && i<0){
                if(my_st.top()<-i) my_st.pop(); 
                else if(my_st.top()==-i){
                    my_st.pop();
                    destroy_cur=true;
                    break;

                } 
                else{
                    destroy_cur=true;
                    break;
                }


            }
            if(destroy_cur==false) my_st.push(i);
        }
        vector<int>ans;
        while(!my_st.empty()){
            ans.push_back(my_st.top());
            my_st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

        
    }
};