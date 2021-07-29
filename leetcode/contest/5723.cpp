#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;
class Solution
{

public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k)
    {

        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < logs.size(); i++)
        {
            mp[logs[i][0]].insert(logs[i][1]);
            // mp[logs[i][0]]++;
        }
        vector<int> res(k);
        int i = 1;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            res[(it->second).size() - 1]++;
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> logs = { {1, 1},{2, 2},{2, 3} };
    int k = 4;
    Solution sl;
    vector<int> ret = sl.findingUsersActiveMinutes(logs, k);
    for (int& i : ret)
    {
        cout << i << endl;
    }
    return 0;
}
