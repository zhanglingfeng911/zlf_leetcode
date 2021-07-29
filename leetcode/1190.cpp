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
    void myReverseStr(string &str, int s, int e) {
        while (s < e) {
            char tmp = str[s];
            str[s] = str[e];
            str[e] = tmp;
            s++;
            e--;
        }
    };


    string reverseParentheses(string s) {

        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int index = stk.top();
                stk.pop();
                myReverseStr(s, index + 1, i - 1);
            }
        }
        string res ="";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == ')') {
                continue;
            }
            res+=s[i];
        }
        return res;
    }
};

int main() {

    Solution sl;
    cout<<sl.reverseParentheses("(u(love)i)")<<endl;
    return 0;
}