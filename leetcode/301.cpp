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
    vector<string> ans;
    set<string> st;

    //"()())()"    ["()()()", "(())()"]
    void dfs(int index, int left_del, int right_del, int left_used, int right_used, string &s, string &cur) {
        if (index == s.size()) {
            if (left_del == 0 && right_del == 0)
                st.insert(cur);
            return;
        }

        if (left_used < right_used) {
            return;
        }

        if (s[index] == '(' && left_del > 0) {
            dfs(index + 1, left_del - 1, right_del, left_used, right_used, s, cur);
        } else if (s[index] == ')' && right_del > 0) {
            dfs(index + 1, left_del, right_del - 1, left_used, right_used, s, cur);
        }

        cur.push_back(s[index]);
        if (s[index] == '(') {
            left_used++;
        } else if (s[index] == ')') {
            right_used++;
        }
        dfs(index + 1, left_del, right_del, left_used, right_used, s, cur);
        cur.pop_back();

    }

    vector<string> removeInvalidParentheses(string s) {
        int len = s.size();
        int left_del = 0, right_del = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                left_del++;
            } else if (s[i] == ')') {
                if (left_del == 0) {
                    right_del++;
                } else {
                    left_del--;
                }
            }

        }

        if (left_del == 0 && right_del == 0) {
            return {s};
        }
        string cur = "";
        dfs(0, left_del, right_del, 0, 0, s, cur);
        if (st.empty()) {
            return ans;
        }
        for (auto it = st.begin(); it != st.end(); ++it) {
            ans.push_back(*it);
        }

        return ans;

    }
};

class Solution2 {
public:
    //lcnt:应该删除的左括号数量 rcnt:应该删除的右括号数量 lnum:已经使用的左括号的数量 rnum:已经使用的右括号的数量
    void dfs(string &s, string &cur, int idx, int lcnt, int rcnt, int lnum, int rnum, set<string> &ans) {
        if (idx == s.size()) {
            if (lcnt == 0 && rcnt == 0) ans.insert(cur);
            return;
        }
        if (lnum < rnum) return; //不合法，剪枝
        if (s[idx] == '(' && lcnt > 0) {  //删除左括号
            dfs(s, cur, idx + 1, lcnt - 1, rcnt, lnum, rnum, ans);
        } else if (s[idx] == ')' && rcnt > 0) {  //删除右括号
            dfs(s, cur, idx + 1, lcnt, rcnt - 1, lnum, rnum, ans);
        }
        //保留该字符
        if (s[idx] == '(') lnum++; //更新计数
        else if (s[idx] == ')') rnum++;
        cur.push_back(s[idx]);
        dfs(s, cur, idx + 1, lcnt, rcnt, lnum, rnum, ans);
        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int lcnt = 0, rcnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') lcnt++;
            else if (s[i] == ')') {
                if (lcnt == 0) rcnt++;
                else lcnt--;
            }
        }
        if (lcnt == 0 && rcnt == 0) return {s};
        vector<string> ans;
        set<string> set;
        string str;
        dfs(s, str, 0, lcnt, rcnt, 0, 0, set);
        for (auto itr = set.begin(); itr != set.end(); itr++)
            ans.push_back(*itr);
        return ans;
    }
};

class Solution3 {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (is_valid(s))
            return {s};
        unordered_set<string> visited;
        queue<string> que;
        visited.insert(s);
        que.push(s);
        vector<string> ans;
        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                auto cur_str = que.front();
                que.pop();
                if (is_valid(cur_str))
                    ans.push_back(cur_str);
                for (int j = 0; j < cur_str.size(); j++) {
                    if (cur_str[j] == '(' || cur_str[j] == ')') {
                        string new_str = cur_str.substr(0, j) + cur_str.substr(j + 1);
                        if (!visited.count(new_str)) {
                            que.push(new_str);
                            visited.insert(new_str);
                        }
                    }
                }

            }

            if (!ans.empty())//有结果就返回==删除最小数量的无效括号
                break;
        }
        return ans;
    }

    /*   bool is_valid(string s) {
           if (s.empty())
               return true;
           stack<char> stk;
           for (auto ch:s) {
               if (ch == '(')
                   stk.push(ch);
               else if (ch == ')') {
                   if (stk.empty())
                       return false;
                   stk.pop();
               }
           }
           return stk.size() == 0;
       }*/

    bool is_valid(string s) {
        int count = 0;
        for (char c:s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
            }
            if (count < 0) {
                return false;
            }

        }
        return count == 0;
    }

/*public boolean isValid(String s) {
        char[] charArray = s.toCharArray();
        int count = 0;
        for (char c : charArray) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }*/


};

int main() {

    Solution s3;
    vector<string> ret = s3.removeInvalidParentheses(")(");
    for (string &str:ret) {
        cout << str << endl;
    }

    return 0;
}