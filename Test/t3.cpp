//
// Created by zlf on 2021/4/2.
//
//
// Created by zlf on 2021/3/31.
//
#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}

class Solution {
public:

    vector<int>direction1 = { 0,1,0,-1 };
    vector<int>direction2 = { 1,0,-1,0 };
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int total = n * n;
        int r = 0, c = 0;
        int orderindex = 0;
        vector<vector<bool>>visited(n,vector<bool>(n));
        for (int i = 1; i <= total; i++)
        {
            ans[r][c] = i;
            visited[r][c] = 1;
            int rr = r + direction1[orderindex], cc = c + direction2[orderindex];
            if (rr < 0||rr>=n||cc<0||cc>=n||visited[rr][cc])
            {
                orderindex = (orderindex + 1) % 4;
                r = r + direction1[orderindex];
                c = c + direction2[orderindex];
            }
            else
            {
                r = rr;
                c = cc;
            }

        }
        return ans;


    }
};


int main01() {
  Solution sl;
  vector<vector<int>>ret=sl.generateMatrix(4);
  for(vector<int>&v:ret)
  {
      for(int &i:v)
      {
          cout<<i<<" ";
      }
      cout<<endl;
  }

  cout<<isalpha('A')<<endl;
  vector<int>a={1,2,3};
  cout<<upper_bound(a.begin(),a.end(),4)-a.begin()<<endl;
    return 0;
}
int main()
{
/*
    int x,y;
    scanf("%d:%d",&x,&y);
    cout<<x<<" "<<y<<endl;*/

    int a;
    char c[128];
    scanf("%d %s",&a,c);
    cout<<a<<" "<<c<<endl;
    return 0;
}