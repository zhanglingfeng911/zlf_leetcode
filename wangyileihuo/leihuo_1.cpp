//
// Created by zlf on 2021/4/1.
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
#include <functional>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}


int main() {

    int N;
    cin>>N;
    using II = pair<int, int>;
    vector<II> rectangle(N);

    for (int i = 0; i < N; ++i) {
        int w, h;
        cin >> w >> h;
        rectangle[i] = {w, h};
    }


    auto func1=[](II&a,II&b)->bool {
        return a.first*a.second<=b.first*b.second;
    };

    auto func2 = [](II &a, II &b) -> bool {

        return min((double)a.first/(double )a.second,(double)a.second/(double )a.first)<=
                min((double)b.first/(double )b.second,(double)b.second/(double )b.first);

    };


    auto func3=[](II&a,II&b)->bool {
        return a.first<=b.first;
    };

    sort(rectangle.begin(),rectangle.end(),func1&&func2&&func3);
    for(int i=0;i<N-1;i++)
    {
        cout<<rectangle[i].first<<" "<<rectangle[i].second;
    }
    cout<<rectangle[N-1].first<<" "<<rectangle[N-1].second<<endl;

    return 0;
}