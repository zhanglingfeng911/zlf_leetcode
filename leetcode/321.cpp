//
// Created by zlf on 2021/4/15.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


struct Node {
    int val;
    int index;

    Node(int _val, int _index) : val(_val), index(_index) {}
};

class Solution {
public:

    int myCompare(vector<int> &nums1,int index1, vector<int> &nums2,int index2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = index1, j = index2;
        while (i < len1 && j < len2) {
            if (nums1[i] != nums2[j]) {
                return nums1[i] - nums2[j];
            }
            i++;
            j++;
        }
        return (len1 - i) - (len2 - j);


    }

    vector<int> merger(vector<int> &nums1, vector<int> &nusm2) {
        int len1 = nums1.size();
        if (len1 == 0) {
            return nusm2;
        }
        int len2 = nusm2.size();
        if (len2 == 0) {
            return nums1;
        }
        int i = 0, j = 0;
        vector<int> ans(len1 + len2);
        int k = 0;
        while (k < len1 + len2) {
            if (i >= len1) {
                ans[k++] = nusm2[j++];
            } else if (j >= len2) {
                ans[k++] = nums1[i++];
            } else if (myCompare(nums1,i,nusm2,j)>0) {
                ans[k++] = nums1[i++];
            } else
                ans[k++] = nusm2[j++];
        }

        return ans;
    }

    vector<int> lagerstK(vector<int> &nums, int k) {
        if (k==0)
        {
            return {};
        }
        int len = nums.size();
        if (k>=len)
        {
            return nums;
        }

        int popNum = len - k;
        vector<int> v;
        for (int i = 0; i < len; ++i) {
            while (popNum && !v.empty() && nums[i] > v.back()) {
                v.pop_back();
                popNum--;
            }
            v.push_back(nums[i]);
        }

        return vector<int>(v.begin(),v.begin()+k);
    }

    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 + len2 < k) {
            return {};
        }
        vector<int> ans;

        for (int i = 0; i <=k; ++i) {
            if (i >len1) {
                break;
            }
            if (k-i<=len2){
                vector<int> ret1 = lagerstK(nums1, i);
                vector<int> ret2 = lagerstK(nums2, k - i);
                vector<int> mergedNum = merger(ret1, ret2);
                if (myCompare(mergedNum, 0,ans,0) > 0) {
                    ans = mergedNum;
                }
            }


        }

        return ans;


    }
};


int main() {

    vector<int>nums1={3,9};
    vector<int>nusm2={8,9};
    Solution sl;
    vector<int>ret=sl.maxNumber(nums1,nusm2,3);
    for (int n:ret) {
        cout<<n<<endl;
    }
    return 0;
}