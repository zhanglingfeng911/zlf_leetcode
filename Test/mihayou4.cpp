#include<iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

string s;
map<int, int> mp;
vector<int> ans;
void build(int l, int r) {
    if(l > r) return;
    // char root = s[l];
    int root = 0;
    int k = l;
    while(isdigit(s[k])) root = root * 10 + (s[k ++] - '0');
    l = k - 1;
    if(s[l + 1] == '(') {
        build(l + 2, mp[l + 1] - 1);
        ans.push_back(root);
        build(mp[l + 1] + 1, r - 1);
    } else ans.push_back(root);
}

void solve() {
    cin >> s;
    stack<int> stk;
    mp.clear();
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')') stk.pop();
        else if(s[i] == ',') mp[stk.top()] = i;
    }
    build(0, s.size() - 1);
    for(auto x : ans) cout << x << ' ';
}
struct  ListNode{

    int _val;
    ListNode* next;
    ListNode(int val):_val(val),next(nullptr){}
};

ListNode *reverseList(ListNode *head,int step)
{
    if (!head) return nullptr;
    ListNode *pre= nullptr;
    ListNode *phead=head;
    int i=0;
    while (i<step)
    {
        ListNode *q=phead->next;
        
        phead->next=pre;
        pre=phead;
        phead=q;
        i++;
    }
    head->next=phead;
    return  pre;

}

ListNode *reverPartLinkedListList(ListNode *head,int l,int r)
{
    if (l>=r) return  head;
    
    int index=0;
    ListNode *dummyHead=new ListNode(0);
    dummyHead->next=head;
    ListNode *phead=head;
    ListNode *pre=dummyHead;
    for (int i = 1; i < l; ++i) {
        pre=phead;
        phead=phead->next;
    }
//    pre->next= nullptr;
    pre->next=reverseList(phead,r-l+1);
    return dummyHead->next;

}

void bianliLIst(ListNode *head)
{
    while (head)
    {
        cout<<head->_val<<" ";
        head=head->next;
    }

}
int main() {
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(4);
    ListNode *l5=new ListNode(5);


    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;

    ListNode *ret=reverPartLinkedListList(l1,1,5);
    bianliLIst(ret);

    return 0;
}