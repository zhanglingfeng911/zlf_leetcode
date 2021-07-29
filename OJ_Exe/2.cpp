//
// Created by zlf on 2021/3/26.
//

//
// Created by zlf on 2021/3/26.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <sstream>
using namespace std;
int main02()
{
    string s;

    while (getline(cin,s))
    {
        istringstream sss(s);//将输入的一行字符串用空格分开分割成一个字符串数组
        vector<string>vec;
        string tmp;
        while(getline(sss,tmp,','))
        {
            vec.push_back(tmp);
        }

        sort(vec.begin(),vec.end());
        for (int i = 0; i < vec.size()-1; ++i) {

            cout<<vec[i]<<',';
        }
        cout<<vec.back()<<endl;
    }

    return 0;
}
