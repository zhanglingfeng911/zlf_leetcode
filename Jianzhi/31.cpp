//
// Created by zlf on 2021/7/17.
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

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();

        stack<int> stk;
        int j = 0;
        for(int i = 0; i < len; ++i) {
            stk.push(pushed[i]);
            while (!stk.empty() && j< len && stk.top() == popped[j]) {
                stk.pop();
                ++j;
            }

        }

        return stk.empty();
    }
};

int main() {


    return 0;
}