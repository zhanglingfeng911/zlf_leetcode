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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();

        int maxGap=0;
        int index=0;
        for (int i = 0; i < len1; ++i) {
            int curGap=abs(nums1[i]-nums2[i]);
            if (curGap>maxGap)
            {
                maxGap=curGap;
                index=i;
            }

        }
        if (maxGap==0)
        {
            return 0;
        }

        int a=nums2[index];
        int mindis=INT_MAX;
        int modIndex=0;
        for (int i = 0; i < len1; ++i) {
            if (i!=index)
            {
                int curdis=abs(nums1[i]-a);
                if (curdis<mindis)
                {
                    mindis=curdis;
                    modIndex=i;

                }
            }
        }
        nums1[index]=nums1[modIndex];
        ll ret=0;
        for (int i = 0; i < len1; ++i) {
            ret+=abs(nums1[i]-nums2[i]);
        }
        return  ret%mod;
    }
};


int main() {

    Solution sl;
    vector<int>nums1 = {1,10,4,4,2,7}, nums2 = {9,3,5,1,7,4};
    cout<<sl.minAbsoluteSumDiff(nums1,nums2)<<endl;

    return 0;
}