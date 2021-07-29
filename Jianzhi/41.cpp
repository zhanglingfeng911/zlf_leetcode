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

class MedianFinder_1 {
public:
   /* * initialize your data structure here.*/
    priority_queue<int,vector<int>,less<int>>smmall_que;
    priority_queue<int,vector<int>,greater<int>>big_que;

    MedianFinder() {


    }

    void addNum(int num) {
        if (smmall_que.size()!=big_que.size()){
            smmall_que.push(num);
            int tmp=smmall_que.top();
            smmall_que.pop();
            big_que.push(tmp);
        }
        else{
            big_que.push(num);
            int tmp=big_que.top();
            big_que.pop();
            smmall_que.push(tmp);
        }

    }

    double findMedian() {
        int num1=smmall_que.top();
        int num2=big_que.top();
        return  (smmall_que.size()==big_que.size())?(double )(num2+num1)/2.0:num1;
    }
};


class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> big_queue;
    priority_queue<int, vector<int>, greater<int>> small_queue;
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        big_queue.push(num);

        small_queue.push(big_queue.top());
        big_queue.pop();

        if(big_queue.size() < small_queue.size()) {
            big_queue.push(small_queue.top());
            small_queue.pop();
        }
    }

    double findMedian() {
        int size_1 = big_queue.size();
        int size_2 = small_queue.size();
        int value_1 = big_queue.top();
        int value_2 = small_queue.top();
        return size_1 == size_2 ? (value_1 + value_2) / 2.0 : value_1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
/*class MedianFinder {
public:
    *//** initialize your data structure here. *//*
    priority_queue<int,vector<int>,less<int>>smmall_que;
    priority_queue<int,vector<int>,greater<int>>big_que;

    MedianFinder() {


    }

    void addNum(int num) {
        if (smmall_que.size()!=big_que.size()){
            big_que.push(num);
            int tmp=big_que.top();
            big_que.pop();
            smmall_que.push(tmp);
        }
        else{
            smmall_que.push(num);
            int tmp=smmall_que.top();
            smmall_que.pop();
            big_que.push(tmp);
        }

    }

    double findMedian() {
        int num1=big_que.top();
        int num2=smmall_que.top();
        return  (smmall_que.size()==big_que.size())?(double )(num2+num1)/2.0:num1;
    }
};*/
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main() {

    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    m.addNum(4);
/*    cout<<m.findMedian()<<endl;
    m.addNum(-5);
//    m.addNum(1);*/
    cout<<m.findMedian()<<endl;

    return 0;

}
