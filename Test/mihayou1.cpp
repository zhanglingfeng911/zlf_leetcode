//
// Created by zlf on 2021/3/28.
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

string p;
int n, m;
void solve() {
    p = "1807";
    string s;
    cin >> s;
    n = s.size();
    m = p.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(s[i - 1] != p[j - 1]) f[i][j] = 0;
            else {
                if(j == 1) f[i][j] = max(f[i - 1][j], 0) + 1;
                else {
                    if(f[i - 1][j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1]) + 1;
                    if(f[i - 1][j]) f[i][j] = max(f[i][j], f[i - 1][j]) + 1;
                }
            }

        }
        ans = max(ans, f[i][m]);
    }
    cout << ans << endl;
}

int main() {
    solve();

    return 0;
}





