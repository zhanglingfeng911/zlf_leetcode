
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
int *a,*b;
auto _initial=[](){
    a=new int[1000];
    b=new int[1000];
    return 0;
}();

class Solution {
public:
    int reinitializePermutation(int n) {
        for(int i=0;i<n;i++)a[i]=i;
        int ans=1;
        while(true){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(i%2)b[i]=a[n/2+(i-1)/2];
                else b[i]=a[i/2];
                if(b[i]==i)cnt++;
            }
            if(cnt==n)break;
            else ans++;
            swap(a,b);
        }
        return ans;
    }
};
class Solution2 {
public:
    const static int N = 1000 + 5;
    bool vis[N];
    int dfs(int u, int n) {
        if(vis[u]) return 0;
        vis[u] = 1;
        if(u % 2 == 0) return dfs(u / 2, n) + 1;
        else return dfs(n / 2 + (u - 1) / 2, n) + 1;
    }
    int reinitializePermutation(int n) {
        int ans = 1;
        for(int i = 0; i < n; i++) if(!vis[i]) {
                int v = dfs(i, n);
                ans = ans / __gcd(v, ans) * v;
            }
        return ans;
    }
};


int main() {


    return 0;
}