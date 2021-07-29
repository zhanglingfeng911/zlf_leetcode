//
// Created by zlf on 2021/5/9.
//
//



#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}

//1. 二分 O(nlgn)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0;
        for (int i = 0; i < nums1.size(); i ++ )
        {
            int l = 0, r = nums2.size() - 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (nums2[mid] >= nums1[i]) l = mid;
                else r = mid - 1;
            }
            if (nums2[l] >= nums1[i] && l >= i) ans =max(ans, l - i);
        }
        return ans;
    }
};

//2 双指针  O(n)
class Solution1 {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + ans+1; j < nums2.size() && nums1[i] <= nums2[j]; j++) {
                ans++;
            }
        }
        return ans;
    }
};

//O(n2)
class Solution2 {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ans = 0;
        for (int i = 0; i < n1; ++i) {
            for (int j = i; j < n2; ++j) {
                if (nums1[i] > nums2[j]) continue;
                ans = max(ans, j - i);
            }
        }
        return ans;

    }
};
//O(n)
class Solution3 {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0;
        int ans = 0;
        for (int j = 0; j < n2; ++j) {
            while (i<=j&&i<n1&&nums1[i]>nums2[j]) {
                ++i;
            }
            if (i<=j&&i<n1) {
                ans=max(ans,j-i);
            }
        }
        return ans;

    }
};


int main() {
    Solution sl;
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nusm2 = {100,20,10,10,5};
    cout<<sl.maxDistance(nums1,nusm2)<<endl;

    return 0;
}