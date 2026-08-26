class Solution {
    bool compare(string s1, string s2){
        if(s1.length() != s2.length())
            return s1.length() < s2.length();
        
        return s1 < s2;
    }
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones = 0;
        for(char& c : s)
            if(c == '1')
                ++ones;
        
        if(ones < k) return "";
        
        string ans = s;
        ones = 0;
        int start = 0;
        for(int end = 0; end < s.length(); ++end){
            if(s[end] == '1') ++ones;
            
            if(ones == k)
                if(compare(s.substr(start, end - start + 1), ans))
                    ans = s.substr(start, end - start + 1);
            
            while(ones == k || s[start] == '0'){
                if(s[start] == '1') --ones;
                ++start;
            }
        }
        return ans;
    }
};