//
// Created by zlf on 2021/3/31.
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
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int len=nums.size();
        for (int i = 0; i < len; ++i) {
            int index=(nums[i]-1)%len;
            nums[index]=nums[index]+len;
        }
        vector<int>res;
        for (int i = 0; i < len; ++i) {
            if (nums[i]<=len){
                res.push_back(i+1);
            }
        }
        return res;

    }
};
int main() {

    Solution sl;
    vector<int>nums={4,3,2,7,8,2,3,1};
    vector<int>ret=sl.findDisappearedNumbers(nums);
    for (int i : ret) {

        cout<<i<<endl;
    }
    return 0;
}