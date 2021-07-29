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


int main() {

    int n;
    cin>>n;
    vector<int>vec(n);
    int sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>vec[i];
        sum+=vec[i];
    }
    cout<<sum-n<<endl;

    return 0;
}
