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


int findKthElement(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); ++i) {
        if (pq.size() < 3) {
            pq.push(nums[i]);
        } else if (nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();

}

void mySwap(vector<int> &(nums), int left, int right) {
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
}

int partition(vector<int> &nums, int left, int right) {
    int pivot = left + rand() % (right - left + 1);
    int pviot_value = nums[pivot];
    mySwap(nums, left, pivot);
    while (left < right) {
        while (left < right && nums[right] >= pviot_value) {
            right--;
        }
        mySwap(nums, left, right);
        while (left < right && nums[left] <= pviot_value) {
            left++;
        }
        mySwap(nums, left, right);

    }
    return left;

}


//快排
int findKthElement2(vector<int> &nums, int left, int right) {

//    if (left < right) {
    int pivot;
    pivot = partition(nums, left, right);
    if (pivot == nums.size() - 3) {
        return nums[pivot];
    } else if (pivot > nums.size() - 3) return findKthElement2(nums, left, pivot - 1);
    else return findKthElement2(nums, pivot + 1, right);


//    }
//    return nums[nums.size() - 3];

}

int main() {
    int num;
    int i = 0;
    vector<int> nums;
    cin.ignore();
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == ']') {
            break;
        }
    }
//    cout << findKthElement(nums) << endl;
    cout << findKthElement2(nums, 0, nums.size() - 1) << endl;

    return 0;
}
