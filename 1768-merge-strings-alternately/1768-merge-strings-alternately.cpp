class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0; int j=0;
        string s="";
        int len1=word1.size();
        int len2=word2.size();
        while(i<len1 || j<len2){
            if(i<len1) s+=word1[i];
            if(j<len2) s+=word2[j];
            i++, j++;
        }
        return s;

        
        
    }
};