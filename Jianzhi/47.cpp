#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:

    int max_value = INT_MIN;
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols, vector<vector<bool>>& visited, int now_value) {
        if(r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c]) {
            return;
        }

        now_value += grid[r][c];
        visited[r][c] = true;
        if(r == rows -1 && c == cols -1) {
            if(now_value > max_value) {
                max_value = now_value;
            }

//            return;
        }

        dfs(grid, r + 1, c, rows, cols, visited, now_value);
        dfs(grid, r, c + 1, rows, cols, visited, now_value);

        visited[r][c] = false;
        return;
    }
    int maxValue(vector<vector<int>>& grid) {

        int n = grid.size();
        if(0 == n) {
            return 0;
        }

        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(grid, 0, 0, n, m, visited, 0);
        return  max_value;
    }
};


int main() {

    vector<vector<int>> nums = {{1,3,1}, {1,5,1}, {4,2,1}};
    Solution sl;
    cout << sl.maxValue(nums) << endl;

    return 0;
}