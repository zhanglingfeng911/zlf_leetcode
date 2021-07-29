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

//1 ok
class Solution2 {
public:
    int translateNum(int num) {
        string str=to_string(num);
//        vector<int>nums;
//        while (num){
//            int tmp=num%10;
//            nums.push_back(tmp);
//            num=num/10;
//        }
//        reverse(nums.begin(),nums.end());
        int len=str.size();
        vector<int>dp(len+1);
        dp[0]=1;
        dp[1] = 1;
        for (int i = 2; i <=len; ++i) {
            dp[i]=dp[i-1];
            int tmp = stoi(str.substr(i-2, 2));
            if(tmp >= 10 && tmp <= 25) {
                dp[i] += dp[i-2];
            }
            /*  if (i>=2&&str[i-1]>='0'&&str[i-1]<='5'&&str[i-2]=='1'||str[i-2]=='2'){

                  dp[i]+=dp[i-2];
              }*/
        }
        return dp[len];

        for(int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1];
            if(i >=2) {
                int tmp = stoi(str.substr(i-2, 2));
                if(tmp >= 10 && tmp <= 25) {
                    dp[i] += dp[i-2];
                }
            }
        }

        return dp[len];
    }
};

class Solution {
public:
    int translateNum(int num) {
        string str=to_string(num);
//        vector<int>nums;
//        while (num){
//            int tmp=num%10;
//            nums.push_back(tmp);
//            num=num/10;
//        }
//        reverse(nums.begin(),nums.end());
        int len=str.size();
        vector<int>dp(len+1);
        dp[0]=1;
        int lastlast=1,last=1;//dp[0] dp[1]
        for (int i = 2; i <=len; ++i) {
            int cur=last;
            string substr=str.substr(i-2,2);//i-1是自己的下标 i-2才是前一个字符的下标
            if (substr>="10"&&substr<="25") {

                cur+=lastlast;
            }
            lastlast=last;
            last=cur;
        }
        return last;//最后Last=cur
    }
};
int main() {
    Solution2 sl;
    cout<<sl.translateNum(25)<<endl;
    cout<<sl.translateNum(12258)<<endl;

    return 0;
}
