class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cng[2] ={0,0};
        for(int i = 0; i < n; i++){
            if(bills[i] == 10){
                if(cng[0] > 0){
                    cng[0]--;
                }else{
                    return false;
                }
                cng[1]++;
            }else if(bills[i] == 20){
                if(cng[1] > 0 && cng[0] > 0){
                    cng[1]--;
                    cng[0]--;
                }else if(cng[1] <= 0 && cng[0] >= 3){
                    cng[0] -= 3;
                }else{
                    return false;
                }
            }else{
                cng[0]++;
            }
        }
        return true;
    }
};