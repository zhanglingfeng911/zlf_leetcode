#include<iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include<list>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Solution1 {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)return 0;

        deque<int> deq;
        for (int i = 0; i < n; i++) {
            deq.push_back(i);
        }

        int idx = 0;
        while (n > 1) {

            idx=(idx+m-1)%n;
            deq.erase(deq.begin()+idx);
            n--;

        }


    }
};
class Solution {
public:
    int lastRemaining(int n, int m)
    {
        list<int>numbers;
        if (n<1||m<1)
        {
            return -1;
        }
        for (int i=0;i<n;i++)
        {
            numbers.push_back(i);
        }

        list<int>::iterator current = numbers.begin();

        while (numbers.size()>1)
        {
            for (int i=1;i<m;i++)
            {
                current++;
                if (current==numbers.end())
                {
                    current = numbers.begin();
                }
            }

            list<int>::iterator next = ++current;
            if (next==numbers.end())
            {
                next = numbers.begin();
            }
            --current;
            numbers.erase(current);

            current = next;


        }

        return(*(current));


    }
};
int main() {
    Solution sl;
    cout<<sl.lastRemaining(5,3)<<endl;

    return 0;
}
