class Solution {
public:
    string decodeString(string s) {
        stack<string> my_st;
        for(char ch: s){
            if(ch != ']') {
                my_st.push(string(1, ch));
            } else {
                string temp = "";
                while(my_st.top() != "["){
                    temp = my_st.top() + temp;
                    my_st.pop();
                }
                my_st.pop(); 
                string num = "";
                while(!my_st.empty() && isdigit(my_st.top()[0])){
                    num = my_st.top() + num;
                    my_st.pop();
                }
                int rep_num = stoi(num);

                string repeated_str = "";
                while(rep_num--){
                    repeated_str += temp;
                }

                my_st.push(repeated_str);
            }
        }

        string ans = "";
        while(!my_st.empty()){
            ans = my_st.top() + ans;
            my_st.pop();
        }
        return ans;
    }
};