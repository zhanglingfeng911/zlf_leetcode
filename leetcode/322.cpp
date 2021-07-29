//
// Created by zlf on 2021/4/7.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int &coin:coins)
        {
            for (int i = 1; i <=amount; ++i) {
                if (i>=coin)
                {
                    dp[i]=min(dp[i-coin]+1,dp[i]);

                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];

    }

};
int main() {
    vector<int>coins={1,2,5};
    int amount=11;
    Solution sl;
    cout<<sl.coinChange(coins,amount)<<endl;

    return 0;
}