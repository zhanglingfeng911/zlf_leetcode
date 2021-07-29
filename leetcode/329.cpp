//
// Created by zlf on 2021/3/29.
//

//#include "bits/stdc++.h"
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int>dir1{-1,1,0,0};
    vector<int>dir2{0,0,-1,1};
    vector<vector<int>>memo;

    int dfs(int r,int c,int rows,int cols,vector<vector<int>>&matrix)
    {

        if (memo[r][c])
        {
            return memo[r][c];
        }
        memo[r][c]++;
//        int ret=0;
        for (int i = 0; i < 4; ++i) {
            int rr=r+dir1[i];
            int cc=c+dir2[i];
            if (rr<0||cc<0||rr>=rows||cc>=cols||matrix[r][c]>=matrix[rr][cc])
            {
                continue;
            }

            memo[r][c]=max(memo[r][c],dfs(rr,cc,rows,cols,matrix)+1);

        }

        return  memo[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if (rows==0)
        {
            return 0;
        }
        int cols=matrix[0].size();
        memo.resize(rows,vector<int>(cols));
        int ret=1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret=max(ret,dfs(i,j,rows,cols,matrix));
            }
        }

        return  ret;

    }
};

class Solution2 {
public:
    vector<int>dir1{-1,1,0,0};
    vector<int>dir2{0,0,-1,1};
    vector<vector<int>>memo;

    int dfs(int r,int c,int rows,int cols,vector<vector<int>>&matrix,int preval)
    {

        if (r<0||c<0||r>=rows||c>=cols||matrix[r][c]<=preval)
        {
            return 0;
        }
        if (memo[r][c])
        {
            return memo[r][c];
        }
        int up=dfs(r+1,c,rows,cols,matrix,matrix[r][c]);
        int down=dfs(r-1,c,rows,cols,matrix,matrix[r][c]);
        int left=dfs(r,c-1,rows,cols,matrix,matrix[r][c]);
        int right=dfs(r,c+1,rows,cols,matrix,matrix[r][c]);
        memo[r][c]=max(max(up,down),max(left,right))+1;

        return memo[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if (rows==0)
        {
            return 0;
        }
        int cols=matrix[0].size();
        memo.resize(rows,vector<int>(cols));
        int ret=1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ret=max(ret,dfs(i,j,rows,cols,matrix,INT_MIN));//因为如果是最小值 也要返回一个1 不然在dfs直接返回0 不合理
            }
        }

        return  ret;

    }
};


class Solution3 {
public:
    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& isVisited, int pre)
    {
        if(row<0 || col<0|| row>= matrix.size() || col>=matrix[0].size() || matrix[row][col]<=pre)
            return 0;

        //已经对该节点进行过求取，直接返回即可
        if(isVisited[row][col] > 0)
            return isVisited[row][col];

        //遍历上下左右节点
        int l = dfs(matrix, row, col-1, isVisited, matrix[row][col]);
        int r = dfs(matrix, row, col+1, isVisited, matrix[row][col]);
        int up = dfs(matrix, row-1, col, isVisited, matrix[row][col]);
        int dow = dfs(matrix, row+1, col, isVisited, matrix[row][col]);

        //存储以该节点为起点的最长增长序列的长度
        isVisited[row][col] = 1 + max(max(l, r), max(up, dow));
        return isVisited[row][col];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int row = matrix.size();
        if(row <= 0)return 0;
        int col = matrix[0].size();

        vector<vector<int>>isVisited(row, vector<int>(col, 0));
        int res = 0;
        //依次求取每一个节点为起点的最长增长序列，并保存最大值。
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
                res = max(res, dfs(matrix, i, j, isVisited, INT_MIN));
        }
        return res;
    }
};
int main()
{
    vector<vector<int>>matrix1={{9,9,4},{6,6,8},{2,1,1}};
    vector<vector<int>>matrix={{3,4,5},{3,2,6},{2,2,1}};
    Solution2 sl;
    cout<<sl.longestIncreasingPath(matrix)<<endl;

    return 0;
}