//
// Created by zlf on 2021/3/30.
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
    int numDecodings(string s) {
        if (s[0]=='0')return 0;
        int lens=s.size();
        vector<int>dp(lens+1);

        dp[0]=1,dp[1]=1;
        for (int i = 2 ; i <=lens ; ++i) {
            if (s[i-1]=='0'){
                if (s[i-2]=='1'||s[i-2]=='2'){
                    dp[i]=dp[i-2];
                }
                else
                    return 0;
            }
            else



                if (s[i-2]=='1'||s[i-2]=='2'&&(s[i-1])>='1'&&s[i-1]<='6'){//自己的下表是i-1 前一个字母的下标是i-2
                    dp[i]=dp[i-1]+dp[i-2];
                }
                else{
                    dp[i]=dp[i-1];
                }

         /*       dp[i]=dp[i-1];
                if ((s[i-2]=='1'||s[i-2]=='2')&&(s[i-1])>='1'&&s[i-1]<='6'){//自己的下表是i-1 前一个字母的下标是i-2
                    dp[i]+=dp[i-2];
                }*/

        }
        return dp[lens];

    }

};
class Solution2 {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n+1,1);
        //dp[0]表示s[-1]的状态， dp[1] 表示 s[0]的状态
        //dp[i] 表示 s[i-1]的状态
        for(int i=2;i<=n;i++){
            if(s[i-1] == '0'){
                if(s[i-2] == '1' || s[i-2] == '2')//唯一译码，不增加情况
                    dp[i] = dp[i-2];
                else//这里要好好理解一下，比如给定340, 输出可行的编码数为0， 因为0和40都无法转换
                    return 0;
            }
            else if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] >= '1' && s[i-1] <= '6')
                dp[i] = dp[i-1] + dp[i-2];
            else//当上述条件都不满足，维持上一个状态
                dp[i] = dp[i-1];
        }
        //for(auto c:dp) cout << c << ",";
        return dp[n];//返回dp[n] 即最后 s[n-1] 的状态
    }
};


int main() {

    Solution sl;
    cout<<sl.numDecodings("226")<<endl;
    cout<<sl.numDecodings("106")<<endl;
    cout<<sl.numDecodings("2101")<<endl;
    cout<<sl.numDecodings("2611055971756562")<<endl;
    Solution2 sl2;
    cout<<sl2.numDecodings("2611055971756562")<<endl;
    return 0;
}
