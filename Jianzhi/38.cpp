//
// Created by zlf on 2021/3/26.
//

#include<iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:
    vector<string>res;
    vector<bool>used;
    void dfs(string path,string &s)
    {
        if (path.size()==s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (!used[i])
            {
                if (i>0&&s[i]==s[i-1]&&used[i-1])
                {
                    continue;
                }
                used[i]= true;
                dfs(path+s[i],s);
                used[i]=false;
            }

        }
    }

    vector<string> permutation(string s) {
        int len=s.size();
        if (len == 1) return vector<string>{s};
        string path="";
        used.resize(s.size());
        dfs(path,s);
        return  res;

    }
};

int main() {

    Solution sl;
    vector<string>ret=sl.permutation("aab");
    for (string &s:ret) {
       cout<<s<<endl;
    }
    cout<<"hello world\n";
    return 0;
}