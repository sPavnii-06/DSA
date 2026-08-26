class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseRec(s, 0, s.size() - 1);
    }
    

    void reverseRec(vector<char>& s, int left, int right) {
        if (left >= right) return;
        swap(s[left], s[right]);
        reverseRec(s, left + 1, right - 1);
    }
};