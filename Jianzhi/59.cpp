//
// Created by zlf on 2021/3/26.
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

class MaxQueue {
public:

    queue<int>real_que;
    deque<int>max_que;

    MaxQueue() {


    }

    int max_value() {
        if (max_que.empty())
        {
            return  -1;
        }
        return  max_que.front();
    }

    void push_back(int value) {

        while (!max_que.empty()&&value>max_que.back())
        {
            max_que.pop_back();

        }

        max_que.push_back(value);
        real_que.push(value);
    }

    int pop_front() {
        if (real_que.empty())
        {
            return  -1;
        }
        int ret=real_que.front();
        real_que.pop();
        if (ret==max_que.front())
        {
            max_que.pop_front();
        }
        return  ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
int main() {

    MaxQueue mq;
    mq.push_back(1);
    mq.push_back(2);
    cout << mq.max_value() << endl;

   cout<<mq.pop_front()<<endl;
   cout<<mq.max_value()<<endl;
    return 0;
}