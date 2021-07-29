//
// Created by zlf on 2021/4/13.
//
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n);//color为0代表没被染色 color为1代表染成了1颜色 color为2代表染成了2颜色
        queue<int>que;

        for (int i = 0; i < n; ++i) {
            if (!color[i]){
                que.push(i);
                color[i]=1;
            }
            while (!que.empty())
            {
                int tmp=que.front();
                que.pop();
                for (int j:graph[tmp]) {
                    if (!color[j]) {
                        que.push(j);
                        color[j]=color[tmp]==1?2:1;

                    } else if (color[j] == color[tmp]) {
                        return false;
                    }
                }


            }

        }

        return true;
    }
};


int main() {

    vector<vector<int>>graph={{1,3},{0,2},{1,3},{0,2}};
    Solution sl;
    cout<<sl.isBipartite(graph)<<endl;

    return 0;
}

