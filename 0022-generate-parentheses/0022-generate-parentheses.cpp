class Solution {
public:
    void parant(int openCnt, int closeCnt, int n, string& temp, vector<string>& ans){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(openCnt < n){
            temp.push_back('(');
            parant( openCnt + 1, closeCnt, n, temp, ans);
            temp.pop_back();
        }
        if(closeCnt < openCnt){
            temp.push_back(')');
            parant( openCnt, closeCnt + 1, n, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> ans;
        parant( 0, 0, n, temp, ans);
        return ans;
    }
};