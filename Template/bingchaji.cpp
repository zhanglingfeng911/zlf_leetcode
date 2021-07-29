//
// Created by zlf on 2021/7/27.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;

class UnionFind {

public:
    int count;
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : count(n) {

        parent.resize(count);
        rank.resize(count);

        for (int i = 0; i < count; ++i) {
            parent[i] = i;
            rank[i] = 1;
        }

    }

    int find(int x) {

        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    void union2P(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);

        if(root_p == root_q) {
            return;
        }

        if(rank[root_p] > rank[root_q]) {

            parent[root_q] = root_p;
            rank[root_p] += rank[root_q];
        } else {

            parent[root_p] = root_q;
            rank[root_q] += rank[root_p];
        }

        --count;
    }

    bool  isconnecnted(int p, int q) {
        int root_p = find(p);
        int root_q = find(q);

        return root_p == root_q;
    }

    int get_count_num() {
        return count;
    }

};


int main() {


    return 0;
}