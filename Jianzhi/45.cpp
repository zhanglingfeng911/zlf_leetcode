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
    string minNumber(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end(),[](int &a,int &b)->bool
        {
           return to_string(a)+to_string(b)<to_string(b)+to_string(a);
        });
        string res="";
        for (int i = 0; i < len; ++i) {
            res+=to_string(nums[i]);
        }
        return res;

    }
};

int main() {

    vector<int>nums={3,30,34,5,9};
    Solution sl;
    cout<<sl.minNumber(nums)<<endl;
    return 0;
}