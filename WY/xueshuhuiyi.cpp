//
// Created by zlf on 2021/4/9.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

unordered_map<int, vector<int>> edges;
vector<int> dfn(50001, 0);
vector<int> low(50001, 0);

vector<bool> instack(50001, false);
stack<int> st;
int dfn_num = 0;
int ans = 0;
void tarjan(int now)
{
    dfn[now]=low[now]=dfn_num++;
    instack[now]=true;
    st.push(now);
    for(auto next:edges[now])
    {
        if (!dfn[next])
        {
            tarjan(next);
            low[now]=min(low[now],low[next]);
        }
        else if (instack[next])
        {
            low[now]=min(low[now],dfn[next]);
        }

    }

    if (dfn[now] == low[now]) {
        int cnt=0;
        int top_elem;
        do {
            top_elem=st.top();
            st.pop();
            cnt++;
            instack[top_elem]= false;

        } while (top_elem!=now);
        if (cnt>1) ans+=(cnt*(cnt-1)/2);
    }
}

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    while (m > 0) {
        int x,y;
        scanf("%d%d",&x,&y);
        edges[x].push_back(y);
        m--;
    }

    for (int i = 1; i <=n ; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    cout<<ans;

    return 0;
}
