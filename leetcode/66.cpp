//
// Created by zlf on 2021/7/25.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();

        int carry = 0;

        for (int i = len - 1; i >= 0; i--)
        {
            int tmp;
            if (i < len - 1)
            {
                tmp = digits[i] + carry ;
            }
            else
                tmp = digits[i] + carry + 1;

            carry = tmp / 10;
            /*if (i==0)
            {
                ret[i] = tmp;

            }*/
            digits[i] = tmp % 10;
            if (carry == 0)
            {
                return digits;
            }




        }
        if (digits[0] == 0)
        {
            digits.resize(len + 1);
            digits[0] = 1;
        }
        return digits;
    }
};



int main() {

    vector<int> nbums = {9,9,9};
    Solution sl;
    vector<int> ans = sl.plusOne(nbums);
    for(int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}