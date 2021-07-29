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
    vector<int> dir1 = {0, 1, 0, -1};
    vector<int> dir2 = {1, 0, -1, 0};

    vector<int>spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(0 == n) {
            return {};
        }
        int m = matrix[0].size();
        int total = n * m;
        vector<int> ans(total);

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int i = 0;
        int order_index = 0;
        int r = 0, c = 0;
        while(i < total) {
            ans[i] = matrix[r][c];
            visited[r][c] = 1;
            int rr = r + dir1[order_index], cc = c + dir2[order_index];
            if(rr < 0 || rr >=n || cc < 0 || cc >= m || visited[rr][cc]) {
                order_index = (order_index + 1) % 4;
                r = r + dir1[order_index];
                c = c + dir2[order_index];
            } else {
                r = rr;
                c = cc;
            }
            ++i;
        }

        return ans;

    }
};

int main() {


    return 0;
}