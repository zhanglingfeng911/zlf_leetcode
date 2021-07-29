//
// Created by zlf on 2021/7/23.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution_1 {
public:
    int add(int a, int b) {

        if(a== 0 || b == 0) {
            return a ^ b;
        }

        return add(a ^ b, (a & b) << 1);

    }


};

class Solution {
public:
    int add(int a, int b) {

        while(b) {
            int tmp = a ^ b;

            b= (a & b) << 1;
            a= tmp;

        }

        return a;
    }


};



int main() {
    Solution sl;
    cout << sl.add(1,1) << endl;

    return 0;
}