class Solution {
public:
    int compress(vector<char>& chars) {
        int r = 0, w = 0, n = chars.size();
        while (r < n) {
            char ch = chars[r];
            int char_cnt = 0;
            
            
            while (r < n && chars[r] == ch) {
                char_cnt++;
                r++;
            }
            
            chars[w] = ch;
            w++;
            

            if (char_cnt > 1) {
                string temp = to_string(char_cnt);
                for (char c : temp) {
                    chars[w] = c;
                    w++;
                }
            }
        }
        return w;
    }
};