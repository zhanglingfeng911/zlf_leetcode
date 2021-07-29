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


int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    vector<int>B(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&A[i]);
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d",&B[i]);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int cnt=0;
    unordered_map<int,int>mp;
    for (int i = 0,j=0; i < N; ++i) {
        mp[A[i]]++;
    }
    for (int i = 0; i < N; ++i) {

        if (mp[B[i]])
        {
            mp[B[i]]--;
            cnt++;
        }
    }
    if (cnt<N) cnt++;//原本全部匹配的，改B会减少一个!!!!（坑)
    else cnt--;
    cout<<cnt<<endl;

    return 0;
}


# include <stdio.h>
int main01()
{
    int k,n=0,a[10]={0},b[10]={0};//定义两个相同长度的数组
    scanf("%d",&n);//获取数组的长度
    for(int i=0;i<n;i++)//通过循环遍历，获取第一个数组中的元素
    {
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
    }

    //遍历第一个数组中的元素
    //将第一个数组中的每个元素去跟第二个数组中的每个元素进行对比
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            //如果Ai==Bj则认为（i，j）为最佳配对。
            //所有的最佳配对在满足以下条件的情况下组成最佳配对集合：
            // A和B中的各个元素最多在集合中出现一次
            //保证a和b不为0

            if(a[i]==b[j]&&b[j]!=0)
            {
                k++;//记录最佳配对的个数
                b[j]=0;//配对之后，就将该元素归0
                break;//跳出for循环，执行外循环
            }//if语句保证是最佳配对
        }

    }
    if(k==n)//最佳配对个数，与数组元素个数相同
    {
        k--;
    }
    else
    {
        k++;

    }
    printf("%d\n",k);
    return 0;
}