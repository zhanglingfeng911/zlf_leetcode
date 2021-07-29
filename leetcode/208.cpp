//
// Created by zlf on 2021/4/14.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


class Trie {
public:
    /** Initialize your data structure here. */



    Trie() {
        next.resize(26, nullptr);
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char c:word) {
            int idnex = c - 'a';
            if (node->next[idnex] == nullptr) {
                node->next[idnex] = new Trie();
            }
            node = node->next[idnex];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char c:word) {
            int idnex = c - 'a';
            if (node->next[idnex] == nullptr) {
                return false;
            }
            node = node->next[idnex];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c:prefix) {
            int index = c - 'a';
            if (node->next[index] == nullptr) {
                return false;
            }
            node=node->next[index];
        }
        return true;

    }

private:
    bool isEnd = false;
    vector<Trie *> next;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {

    Trie trie;
    trie.insert("apple");
    cout<<trie.search("apple")<<endl;
    cout<<trie.search("app")<<endl;
    cout<<trie.startsWith("app")<<endl;
    trie.insert("app");
    cout<<trie.search("app")<<endl;
    return 0;
}