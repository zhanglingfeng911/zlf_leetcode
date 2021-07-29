//
// Created by zlf on 2021/7/18.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long , vector<long long>, greater<long long>> pq;
        unordered_set<long long> st;
        st.insert(1);
        pq.push(1);
        vector<int> f{2, 3, 5};

        for (int i = 0; i < n - 1; ++i) {

            long long v = pq.top();
            pq.pop();
            for(int num : f) {
                long long tmp =num * v;
                if (st.find(tmp) == st.end()) {
                    st.insert(tmp);
                    pq.push(tmp);
                }
            }

        }

        return pq.top();
    }
};

int main() {


    return 0;
}