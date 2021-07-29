//
// Created by zlf on 2021/7/25.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int len = s.size();
        vector<bool> mark(len, false);

        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') {
                stk.push(i);
            } else {

                if(stk.empty()) {
                    mark[i] = true;
                }

                stk.pop();
            }
        }

        while (!stk.empty()) {
            mark[stk.top()] = 1;
            stk.pop();
        }

        int max_len = 0;
        int cur_len = 0;
        for(int i = 0; i < len; ++i) {
            if(mark[i]) {
                cur_len = 0;
                continue;
            }

            ++cur_len;
            max_len = max(max_len, cur_len);
        }


        return max_len;

    }
};



class Solution_2 {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> dp(len);
        int max_len = 0;
        for(int i = 1; i < len; ++i) {
            if(s[i] == ')') {

                if(s[i - 1] == '(') {
                    dp[i] = i >=2 ? dp[i - 2] + 2 : 2;

                } else if(i - dp[i - 1] > 1 && s[i - dp[i-1] -1] == '(') {
                    dp[i] = dp[i -1] + 2;
                    if(i -dp[i-1] -2 > 0) {
                        dp[i] += dp[i - dp[i-1] -2];
                    }
                }

            }

            max_len = max(max_len, dp[i]);

        }
        return max_len;

    }

};


int main() {


    return 0;
}