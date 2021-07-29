//
// Created by zlf on 2021/4/15.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        int len = num.size();
        if (len == 0) {
            return "0";
        }
        if (k >= len) {
            return "0";
        }
        for (int i = 0; i < len; ++i) {
            while (k && !stk.empty() && num[i] < stk.back()) {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }
        vector<char> res(stk.begin(), stk.begin() + (len - k));
//        string ans="";
        /*while (!stk.empty()){
            char tmp=stk2.top();
            stk.pop();
            ans.push_back(tmp);
        }*/
        string ans = "";
        int j = 0;
        while (res[j] == '0') {
            j++;
        }
        while (j<res.size())
        {
            ans+=res[j];
            j++;
        }
        if (ans.empty()) {
            return "0";
        }
//        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution sl;
    cout << sl.removeKdigits("10200", 1) << endl;

    return 0;
}