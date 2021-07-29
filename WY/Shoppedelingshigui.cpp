//
// Created by zlf on 2021/3/29.
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

const int MAXN = 1e6;

int a[MAXN + 5];
int n, m;

int myBinSear(int left, int right) {
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        int tsum = 0, cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (tsum + a[i] > mid) {
                cnt++;
                tsum = a[i];
            } else {
                tsum += a[i];
            }
        }
        if (cnt < m) {
            right = mid-1;
        } else if(cnt>m)
            left = mid + 1;
        else
            right=mid;
    }
//    printf("%d\n",left);
    return left;


}

int main() {

    scanf("%d%d", &n, &m);
        int right = 0, left = 0;
        vector<int>A(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            left = max(A[i], left);
            right += A[i];
        }

        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int tsum = 0, cnt = 1;
            for (int i = 0; i < n; ++i) {
                if (tsum + A[i] > mid) {
                    cnt++;
                    tsum = A[i];
                } else {
                    tsum += A[i];
                }
            }
            if (cnt <= m) {
                right = mid;
            } else
                left = mid + 1;

        }
//        cout<<myBinSear(left,right)<<endl;
        cout << left << endl;


}

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
void solu(vector<int> &A,int n,int m,int l,int r){
    while(l<r){
        int mid = (l + r) / 2;
        int cnt = 1, sum = 0;
        for (int i = 0; i < n;++i){
            if(sum+A[i]<=mid)
                sum += A[i];
            else{
                sum = A[i];
                cnt++;
            }
        }
        if(cnt>m)
            l = mid + 1;
        else if(cnt<m)
            r = mid - 1;
        else
            r = mid;
    }
    printf("%d\n", l);
}
int main01(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> A(n);
    int max = 0, sum = 0;
    for (int i = 0; i < n;++i){
        scanf("%d", &A[i]);
        if(A[i]>max)
            max = A[i];
        sum += A[i];
    }
    solu(A, n, m, max, sum);
    return 0;
}

/*
void bSearch(int lower,int upper){
    int mid;
    while(lower<=upper){
        mid = (lower+upper)>>1;
        int curSum = 0,cnt=0;
        bool flag = 1;
        for(int i=0;i<n;){
            while(i<n&&curSum+a[i]<=mid){
                curSum+=a[i];
                i++;
            }
            cnt++;
            if(cnt>m) {
                flag = 0;
                break;
            }
            curSum = 0;
        }
        if(flag) upper = mid-1;
        else lower = mid+1;
    }
    printf("%d\n",mid);
}

int main() {
    while(~scanf("%d%d",&n,&m)){
        int MAX = 0 ,sum = 0;
        for(int i=0;i<n;i++) {
            scanf("%d", &a[i]);
            MAX = max(MAX, a[i]);
            sum += a[i];
        }
        bSearch(MAX,sum);
    }
    return 0;
}
*/
