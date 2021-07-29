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


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,less<int>>pq;
        int len=arr.size();
        for (int i = 0; i < len; ++i) {
            if (pq.size()<k){
                pq.push(arr[i]);
            }
            else{
                if(arr[i]<pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }

        }

        vector<int>res(k);
        for (int i = 0; i < k; ++i) {
            res[i]=pq.top();
            pq.pop();
        }
        return  res;

    }
};

int main() {

    vector<int>nums={5,2,3,1};
    Solution sl;
    vector<int>ret=sl.getLeastNumbers(nums,3);
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i]<<endl;
    }

    return 0;
}
