class Solution {
public:
        bool vowel(char ch){
            ch=tolower(ch);
            if(ch=='a'|| ch=='i'||ch=='o'||ch=='e'||ch=='u') return true;
            else return false;
        }
    string reverseVowels(string s){
        int left=0, right=s.size()-1;
        while(left<right){
            while(left<right && !vowel(s[left]))left++;
            while(left<right && !vowel(s[right]))right--;
            swap(s[left],s[right]);
            left++, right--;
        }
        return s;
    }
};