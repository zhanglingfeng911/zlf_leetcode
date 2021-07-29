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


#include<iostream>
using namespace std;

bool check(string s)
{
    int flage=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            return false;
        }
        if(s[i]==s[i+1])
        {
            return false;
        }
    }
    for(int i=0;i<s.size()-3;i++)
    {
        for(int j=i+1;j<s.size()-2;j++)
        {
            for(int p=j+1;p<s.size()-1;p++)
            {
                if(s[i]==s[p])
                {
                    for(int q=p+1;q<s.size();q++)
                    {
                        if(s[j]==s[q])
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    string s;
    while(cin>>s)
    {
        bool n=check(s);
        if(n)cout<<"Likes"<<endl;
        else cout<<"Dislikes"<<endl;
    }
}
