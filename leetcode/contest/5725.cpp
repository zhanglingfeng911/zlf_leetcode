//
// Created by zlf on 2021/4/4.
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
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int c = *max_element(nums.begin(), nums.end());
        vector<int> g(c + 1);

        for (int x: nums) {
            for (int y = 1; y * y <= x; ++y) {
                if (x % y == 0) {
                    if (!g[y]) {
                        g[y] = x;
                    }
                    else {
                        g[y] = gcd(g[y], x);
                    }
                    if (y * y != x) {
                        int z = x / y;
                        if (!g[z]) {
                            g[z] = x;
                        }
                        else {
                            g[z] = gcd(g[z], x);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= c; ++i) {
            if (g[i] == i) {
                ++ans;
            }
        }
        return ans;
    }
};




int main() {
    vector<int>nums={6,10,3};
    Solution sl;
    cout<<sl.countDifferentSubsequenceGCDs(nums)<<endl;

    return 0;
}