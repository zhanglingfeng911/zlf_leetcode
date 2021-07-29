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
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1));

        for (int i = 0; i <=n; ++i) {
            for (int j = 0; j <=m; ++j) {
                //如果模式串为空，判断
                if (j==0)
                {
                    dp[i][j]=i==0;
                }//模式串不为空
                else{
                    if (p[j-1]!='*')//如果模式串为正常字符
                    {
                        if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') ){
                            dp[i][j]=dp[i-1][j-1];
                        }
                    }
                    else//如果模式串的字符为*
                    {
                        if (j>=2)//不要p后面2个字符
                        {
                            dp[i][j]=dp[i][j]||dp[i][j-2];
                        }

                        if (i>=1&&j>=2&&(s[i-1]==p[j-2]||p[j-2]=='.'))
                        {
                            dp[i][j]=dp[i][j]||dp[i-1][j];
                        }
                    }
                }

            }
        }

        return dp[n][m];

    }
};

int main() {

    string s="aa";
    string p="a*";
    Solution sl;
    cout<<sl.isMatch(s,p)<<endl;
    return 0;
}

