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


int main()
{
    int R,x1,y1,x2,y2,x3,y3,x0,y0;
    auto FUNC=[&](int &x1,int &y1,int &x2,int &y2)->int
    {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    };
    while(cin>>R>>x1>>y1>>x2>>y2>>x3>>y3>>x0>>y0)
    {
        int cnt=0;
       int r1=FUNC(x1,y1,x0,y0);
        if (r1<=R*R) ++cnt;
        int r2=FUNC(x2,y2,x0,y0);
        if (r2<=R*R) ++cnt;
        int r3=FUNC(x3,y3,x0,y0);
        if (r3<=R*R) ++cnt;
        cout<<cnt<<"x"<<endl;
    }

    return 0;
}