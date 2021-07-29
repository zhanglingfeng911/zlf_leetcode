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

    string str;
    while (cin>>str){
        int len=str.size();
        int ret=1;
        int maxLen=1;
//    vector<int>count(2);
        for (int i = 0; i < len; ++i) {
            if (i<len-1&&str[i]!=str[i+1])
            {
                ret+=1;
            }
            else
            {
                ret=1;
//            i++;
            }
            maxLen=max(maxLen,ret);
        }

        cout<<maxLen<<endl;
    }


    return 0;
}
