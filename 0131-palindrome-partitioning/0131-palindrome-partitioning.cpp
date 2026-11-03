class Solution {
public:
    int n;
    bool isPalin(string str){
        int nn = str.size();
        for(int i = 0; i < nn/2; i++){
            if(str[i] != str[nn - i - 1]) return false;
        }
        return true;
    }
    void palindrome(int idx, string& s, vector<string>& temp, vector<vector<string>>& ans){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        string str = "";
        for(; idx < n; idx++){
            str.push_back(s[idx]);
            if(isPalin(str)){
                temp.push_back(str);
                palindrome(idx+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> temp;
        vector<vector<string>> ans;
        palindrome(0, s, temp, ans);
        return ans;
    }
};