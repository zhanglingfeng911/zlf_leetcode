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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> Indegree(n);
        vector<int> Adj[n];
        for (int i = 0; i < edges.size(); ++i) {
            Indegree[edges[i][1]]++;
            Indegree[edges[i][0]]++;
            Adj[edges[i][0]].push_back(edges[i][1]);
            Adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> que;

        for (int i = 0; i < n; ++i) {
            if (Indegree[i] == 1) {
                que.push(i);
            }
        }

        vector<int> ans;

        while (!que.empty()) {
            ans.clear();
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                int tmp = que.front();
                ans.push_back(tmp);
                que.pop();
                for (int j = 0; j < Adj[tmp].size(); ++j) {
                    Indegree[Adj[tmp][j]]--;
//                    Indegree[Adj[j][tmp]]--;
                    if (Indegree[Adj[tmp][j]] == 1) {
                        que.push(Adj[tmp][j]);
                    }

                }
            }

        }

        return ans;
    }
};

int main() {
    int n=6;
    vector<vector<int>> edges = {{3, 0},
                                 {3, 1},
                                 {3, 2},
                                 {3, 4},
                                 {5, 4}};
    Solution sl;
    vector<int>ret=sl.findMinHeightTrees(n,edges);
    for (int n:ret) {
        cout<<n<<endl;
    }

    return 0;
}