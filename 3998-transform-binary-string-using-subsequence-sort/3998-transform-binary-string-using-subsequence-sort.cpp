class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int s_zeros = count(s.begin(), s.end(),'0');
        vector<int> pref_s(s.size());

        for(int i=0 , c=0;i<s.size(); i++){
            pref_s[i] = (c += (s[i]=='0'));
            
        }
        vector<bool> ans;
        for(const string & t: strs){
            int t_zeros = count(t.begin(), t.end(),'0');
            int q = count( t.begin(),t.end(), '?');

             if (t_zeros > s_zeros || t_zeros + q < s_zeros) {
                 ans.push_back(false);
                continue;
            }
             int need = s_zeros - t_zeros;
             int cur_zeros = 0;
             bool ok = true;

            for (int i = 0; i < s.size(); ++i) {
                if (t[i] == '0' || (t[i] == '?' && need-- > 0)) {
                    cur_zeros++;
        }
                 if (cur_zeros < pref_s[i]) {
                    ok = false;
                    break;
                }
            }
            ans.push_back(ok);
        }
        
        return ans;
        
    }
};