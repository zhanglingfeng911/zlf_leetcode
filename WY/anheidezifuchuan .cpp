//
// Created by zlf on 2021/3/31.
//
//
// Created by zlf on 2021/3/31.
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

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}


#include <iostream>
using namespace std;
int main(){
    int n = 0;
    while(cin >> n){
        long long dp[31] = {0};
        dp[1] = 3, dp[2] = 9;
        for( int i = 3; i <= n; i++ )
            dp[i] = 2*dp[i-1]+dp[i-2];
        cout<<dp[n]<<endl;
    }
}
