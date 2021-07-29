//
// Created by zlf on 2021/3/30.
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


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//迭代2
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead=new ListNode(0);
        ListNode *head=dummyHead;

        while (l1&&l2){
            if (l1->val<=l2->val){
                head->next=l1;
                head=l1;
                l1=l1->next;
            } else{
                head->next=l2;
                head=l2;
                l2=l2->next;
            }
        }
        head->next=l1?l1:l2;
        return dummyHead->next;
    }
};


//递归1
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1){
            return l2;
        }
        if (!l2){
            return l1;
        }

        if (l1->val<=l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }


    }
};

int main() {


    return 0;
}