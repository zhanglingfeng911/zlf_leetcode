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


int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>>g(n,vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>g[i][j];
        }
    }
    int startX,startY;
    cin>>startX>>startY;
    int k;
    cin>>k;

    vector<vector<int>>dis(n,vector<int>(m,-1));
    using II=pair<int,int>;
    vector<II>dir(k);
    for (int i = 0; i < k; ++i) {
        int x,y;
        cin>>x>>y;
        dir[i]={x,y};
    }

    queue<II>que;
    que.push({startX,startY});
    dis[startX][startY]=0;
    int maxDis=0;
    while (!que.empty())
    {
        int size=que.size();
        II tmp=que.front();
        que.pop();
        int x=tmp.first,y=tmp.second;
        for (int i = 0; i < k; ++i) {
            int xx=x+dir[i].first,yy=y+dir[i].second;
            if (xx>=0&&xx<n&&yy>=0&&yy<m&&dis[xx][yy]==-1&&g[xx][yy]=='.')//&&g[xx][yy]=='.'
            {
                que.push({xx,yy});
                dis[xx][yy]=dis[x][y]+1;
                maxDis=max(maxDis,dis[xx][yy]);

            }

        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j]=='.'&&dis[i][j]==-1)
            {
                cout<<-1<<endl;
                return 0;

            }
        }
    }
    cout<<maxDis<<endl;

    return 0;
}
/*
 * #include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, res = -1;
int startx, starty;
vector<pair<int, int>> d;
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }
    cin >> startx >> starty;
    dist[startx][starty] = 0;
    q.push({startx, starty});
    cin >> k;
    for (int i = 0; i < k; i ++) {
        pair<int, int> t;
        cin >> t.first >> t.second;
        d.push_back(t);
    }

    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < k; i ++) {
            int x = t.first + d[i].first, y = t.second + d[i].second;
            if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1 && g[x][y] == '.') {
                dist[x][y] = dist[t.first][t.second] + 1;
                res = max(res, dist[x][y]);
                q.push({x, y});
//                 cout << "true" << endl;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (dist[i][j] == -1 && g[i][j] == '.') res = -1;
        }
    }
    cout << res;
    return 0;
}
 * */