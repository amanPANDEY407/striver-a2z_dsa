class Solution {
public:
    bool rotateString(string s, string goal) {
        string ans = "";
        int n = s.length();
        if(s.length() != goal.length()){
            return false;
        }
        if(s == goal){
            return true;
        }
        for(int i = 1; i < s.length(); i++){
            ans = s.substr(i, n - i) + s.substr(0,i);
            if(goal == ans){
                return true;
            }
        }
        return false;
    }
};