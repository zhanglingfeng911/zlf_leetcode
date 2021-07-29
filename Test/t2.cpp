#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


int ans[10005];
vector<pair<int, int>>vec;
int n;
void solve()
{

    for (int num = 0; num <= 100; ++num)
    {
        unordered_map<int, int>mp;
        int curNum = 0;
        for (int i = 0; i < n; i++)
        {
            int val = vec[i].first * num + vec[i].second;
            mp[val]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            curNum = it->second;//表示有几条直线相较于同一点
            ans[curNum]++;//表示有curNum直线相交的种类都要++
        }

    }
}



int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k, b;
        cin >> k >> b;

        vec.push_back(make_pair(k, b));
    }

    solve();
    for (int i = 2; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n] << endl;

    return 0;
}
/*
3
2 0
0 2
-1 3
*/