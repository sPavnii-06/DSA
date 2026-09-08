class Solution {
public:
    vector<string> ans = {"", "", "abc", "def", "ghi", "jkl",
                          "mno", "pqrs", "tuv", "wxyz"};

    void solve(string &digits, int i, string &temp, vector<string> &res) {
        if (i == digits.size()) {
            res.push_back(temp);
            return;
        }

        for (char c : ans[digits[i] - '0']) {
            temp += c;
            solve(digits, i + 1, temp, res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string temp;
        solve(digits, 0, temp, res);
        return res;
    }
};