class Solution {
public:
    static bool comparator(pair<int, char> p1, pair<int, char> p2){
        if(p1.first > p2.first) return true;
        if(p1.first < p2.first) return false;
        return p1.second < p2.second;
    }
    string frequencySort(string s) {
        pair<int, char> freq[123];
        for(int i = 0; i < 123; i++){
            freq[i].first = 0;
            freq[i].second = '\0' + i;
        }
        for(int  i = 0; i < s.length(); i++){
            freq[s[i] - '\0'].first++;
        }
        sort(freq, freq + 123, comparator);
        s = "";
        for (int i = 0; i < 123; i++) {
          for(int j = 0; j < freq[i].first; j++) {
             s += freq[i].second;
         }
       }
       return s;
    }
};