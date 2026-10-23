class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        pair<int,int> p(-1,0);
        pair<int,int> q(-1,0);
        int l,r,len;
        l = r = len = 0;
        while(r < n){
            int x = fruits[r];
            while((x != p.first && x != q.first) && (p.second != 0 && q.second != 0)){
                fruits[l] == p.first?p.second--:q.second--;
                l++;
            }
            if(p.first == x){
                p.second++;
            }else if(q.first == x){
                q.second++;
            }else if(p.second == 0){
                p.first = x;
                p.second++;
            }else if(q.second == 0){
                q.first = x;
                q.second++;
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};