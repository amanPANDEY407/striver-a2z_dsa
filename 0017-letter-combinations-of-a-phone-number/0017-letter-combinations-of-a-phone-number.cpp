class Solution {
public:
    void solve(int idx, string& digits, string& temp, vector<string>& ans, vector<string>& pad){
        if (idx == digits.length()){
            ans.push_back(temp);
            return;
        }
        string letters = pad[digits[idx] - '0'];
        for(char ch : letters){
            temp.push_back(ch);
            solve(idx + 1, digits, temp, ans, pad);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp = "";
        solve(0, digits, temp, ans, pad);
        return ans;
    }
};