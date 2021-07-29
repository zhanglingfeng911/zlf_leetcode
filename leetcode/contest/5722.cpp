//
// Created by zlf on 2021/4/4.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+50;
const ll mod=1e9+7;

class Solution {
public:

    /*  vector<string> split(string s)
     {
         vector<string>res;
         stringstream ss(s);
         string tmp;
         while (getline(ss,tmp,' '))
         {
             res.push_back(tmp);
         }
         return res;
     } */
    string truncateSentence(string s, int k) {
        int len=s.size();
        string res="";
        int count=0;
        int i = 0;
        for (; i < len; i++)
        {
            int index=i;
            while (i<len&&s[i]!=' ')
            {
                i++;
            }
            count++;
            if (count==k)
            {
                break;
            }

        }
        return s.substr(0,i);

    }
};

int main()
{

    Solution sl;
    string s = "What is the solution to this problem";
    cout<<sl.truncateSentence(s,4)<<endl;


    return 0;
}
