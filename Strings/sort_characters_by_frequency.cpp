#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        string res = "";
        while (!pq.empty()) {
            int count = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            res.append(count, ch);
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;
    return 0;
}