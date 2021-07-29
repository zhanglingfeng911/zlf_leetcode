//
// Created by zlf on 2021/3/27.
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
#include<condition_variable>
#include <mutex>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


int main() {
    vector<int>vec;
    vec.push_back(1);
    cout<<vec.capacity()<<endl;
    for(int i=2;i<6;i++)
    {cout<<vec.capacity()<<endl;
        vec.push_back(i);
    }

    cout<<vec.capacity()<<endl;

    using PII = pair<int, int>;
    using FUNC = function<bool(PII& a, PII& b)>;
    priority_queue<PII, vector<PII>, FUNC>pq([](PII& a, PII& b)->bool
                                             {
                                                 return a.second<b.second||((a.second==b.second)&&a.first>b.first);
                                             });


    pq.push({3,3,});
    pq.push({2,3,});
    pq.push({1,6,});
    pq.push({1,9,});

    while (!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}