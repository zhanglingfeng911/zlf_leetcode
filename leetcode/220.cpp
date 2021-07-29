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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len=nums.size();
        set<long>st;
        for (int i = 0; i < len; ++i) {
            auto index= st.lower_bound(long (nums[i])-t);
            if (index != st.end() && *index <= long(nums[i] )+ t) {
                return true;
            }
            st.insert(nums[i]);
            if (st.size() > k) {
                st.erase(nums[i-k]);
            }
        }
        return false;
    }
};

int main() {


    return 0;
}
