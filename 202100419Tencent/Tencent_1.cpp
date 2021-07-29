#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1010;
const ll mod = 1e9 + 7;

struct Node {
    int id;
    int time;
    int score;

    Node(int _id = 0, int _time = 0, int _score = 0) : id(_id), time(_time), score(_score) {}

} node[N];


/*
 1
 3
 3 1 1
 3 6 9
 *
 */

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        for (int i = 0; i < n; ++i) {
            int t;
            int s;
            cin >> t;
            cin >> s;
            node[i].id = i;
            node[i].time = t;
            node[i].score = s;
        }


//        using FUNC = function<bool(Node &a, Node &b)>;
//        priority_queue<Node, vector<Node>, FUNC> pq([&](Node &a, Node &b) -> bool
//        {
//            return (a.score<b.score)||((a.score==b.score)&&(a.time>b.time));
//        });
        sort(node, node + n, [](Node &a, Node &b) -> bool {
            return a.score > b.score || ((a.score == b.score) && (a.time < b.time));
        });
        int needSub = 0;
        int t = 0;
        int index = 0;
        for (int i = 0; i < n; ++i) {
//            if (pq.empty())
//            {
//
//            }
            if (index < n) {
                t = max(t, node[index++].time);
            }
            /*if (index < n && node[index].time <= t) {
                pq.push(node[index++]);
            }*/

            while (index < n && node[index].time <= t) {
                needSub += node[index++].score;
            }

        }
        cout<<needSub<<endl;

    }

    return 0;
}