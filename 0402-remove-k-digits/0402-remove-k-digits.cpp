#include <string>

class Solution {
public:
    string removeKdigits(std::string num, int k) {
        string result = "";
        for (char ch : num) {
            while (!result.empty() && result.back() > ch && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(ch);
        }
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};