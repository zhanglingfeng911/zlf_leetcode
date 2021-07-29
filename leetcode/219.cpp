//
// Created by zlf on 2021/4/14.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < len; ++i) {
            if (mp.count(nums[i]) == 0) {
                mp[nums[i]] = i;
            } else {
                if ((i - mp[nums[i]]) <= k) {
                    return true;
                } else {
                    mp[nums[i]] = i;
                }
            }


        }
        return false;

    }
};


class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < len; ++i) {


            if (st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
            if (st.size() > k) st.erase(nums[i - k]);

        }
        return false;

    }
};

int main() {
    Solution2 sl;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << sl.containsNearbyDuplicate(nums, k) << endl;


    return 0;
}