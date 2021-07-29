//
// Created by zlf on 2021/3/29.
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

#include <bits/stdc++.h>
using namespace std;

int main02(){

    string s;

    int T;
    cin>>T;
    while(T--){
        cin>>s;
        int l = s.length(), p=-1;
        string t(s.rbegin(), s.rend());
        for(int i=0;i<l;i++)
            if(s[i]!=t[i]){
                p = (s[i]==t[i+1])?l-i-1:i;
                break;
            }
        cout<<p<<endl;
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int deleteIndex(string &str)
{
    int i = 0;
    int j = str.length() - 1;
//    while(i <= (str.length() - 1) / 2 && j >= str.length() / 2)
    while(i <j)
    {
        if(str[i] == str[j])
        {
            i++;
            j--;
        }
        else
        {
            if(str[i + 1] == str[j])
                return i;
            else if(str[i] == str[j - 1])
                return j;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        cout << deleteIndex(str) << endl;
    }
    return 0;
}


int main01() {


    int T;
    cin>>T;
    while (T--)
    {




    }
    return 0;
}
