//
// Created by zlf on 2021/4/15.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>hash(n);

        for (int i = 0; i < n; ++i) {
            for (char c:words[i]) {
                hash[i]|=1<<(c-'a');
            }
        }
        int ans=0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((hash[i] & hash[j]) == 0) {
                    int len1=words[i].size();
                    int len2=words[j].size();
                    ans=max(ans,len1*len2);
                }
            }
        }

        return ans;

    }
};
int main() {

    Solution sl;
    vector<string>words={"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << sl.maxProduct(words);
    return 0;
}