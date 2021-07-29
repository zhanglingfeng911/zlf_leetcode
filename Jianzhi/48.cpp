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
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int maxLen=0;
        int left=0,right=0;
        vector<int>count(128);
        while (right<len)
        {
            char c=s[right];
            count[c]++;
            while (left<right&&count[c]>1)
            {
                char le=s[left];
                count[le]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;


    }
};


int main() {
    Solution sl;
    cout<<sl.lengthOfLongestSubstring("pwwkew")<<endl;

    return 0;
}