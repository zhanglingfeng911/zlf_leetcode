//
// Created by zlf on 2021/7/24.
//

#include<bits/stdc++.h>
//#include <sstream>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


vector<string> mysplit(string str, char delim) {

    vector<string> ans;
    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, delim)) {
        ans.push_back(tmp);
    }

    return ans;
}

int main() {

    vector<int> nums = {1,2,3,4,5,6};
    for(auto it = nums.begin(); it != nums.end(); ++it) {

        if(*it = 2) {
            it = nums.insert(it, *it + 3);
            cout << *it << endl;
            break;
        }
    }

    return 0;


}

int main_1() {

    int c, d;

    while (scanf("%d %d", &c, &d) != EOF) {
        if(c == 0 || d == 0) {
            break;
        }
        cout << c + d << endl;

    }


    int a;
    cin >> a;
    string str = "abc cd e";
    vector<string> ans = mysplit(str, ' ');
    for (string str : ans) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}