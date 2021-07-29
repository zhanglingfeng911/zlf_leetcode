//
// Created by zlf on 2021/4/11.
//

#include"bits/stdc++.h"

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


int dp[3];

int main01() {

    unordered_map<int, int> mp;
    mp[1] = 2;
    cout << mp[1] << endl;
    cout << mp.size() << endl;

    fill(dp, dp + 3, 55);
    for (int i = 0; i < 3; ++i) {
        cout << dp[i] << endl;
    }
    return 0;
}

struct Node
{
    int val;
    string name;
    Node(int _val,string _name):val(_val),name(_name){}
};

void test() {
    using FUNC=function<bool(Node &a,Node &b)>;


    priority_queue<Node,vector<Node>,FUNC>pq([](Node &a,Node &b)->bool
    {
        return a.val<b.val;
    });

    pq.push(Node(1,"sdfa"));
    pq.push(Node(4,"sdfa"));
    pq.push(Node(3,"sdfa"));
    pq.push(Node(2,"sdfa"));

    while (!pq.empty()) {
        cout<<pq.top().val<<endl;
        pq.pop();
    }

};

int main() {
    test();
    int a[10];
    cout << sizeof(a) << endl;
    char b[] = "abc";
    cout << sizeof(b) << endl;
    cout << strlen(b) << endl;
    int c = 4;
    assert(c == 4);
    return 0;

}