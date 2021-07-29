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
#include <set>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

long long gcd(long long m, long long n) {
    return n == 0 ? m : gcd(n, m % n);

}
class Solution {
public:
    int numDifferentIntegers(string word) {
        int count=0;
        unordered_set<string >set;
        int len=word.size();
        for (int i = 0; i <len ;) {
            if (isdigit(word[i])){
                string cur="";
                int j;
                for (j=i; j < len&&isdigit(word[j]); ++j) {
                    if (word[j]=='0'){
                        if (!cur.empty())
                        {
                            cur+=word[j];
                        }
                    }
                    else
                        cur+=word[j];
                }
                if (cur.empty()){//说明它就是数字0 不是什么前导0
                    cur="0";
                }
                set.insert(cur);
                i=j+1;//j不是数字 直接跳过
            }
            else{
                i++;
            }

        }
        return set.size();

    }
};

int main() {

    Solution sl;
    cout<<sl.numDifferentIntegers("a1b01c001")<<endl;
    return 0;
}