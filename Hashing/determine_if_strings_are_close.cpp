#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> wm1;
        unordered_map<char, int> wm2;

        for (char a : word1) wm1[a]++;
        for (char a : word2) wm2[a]++;

        if (wm1 == wm2) return true;

        for (auto it : wm1) {
            char ch = it.first;
            if (wm2.find(ch) == wm2.end()) return false;
        }

        vector<int> freq1, freq2;
        for (auto it : wm1) freq1.push_back(it.second);
        for (auto it : wm2) freq2.push_back(it.second);

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};

int main() {
    Solution solution;

    string word1 = "abc";
    string word2 = "bca";

    if (solution.closeStrings(word1, word2)) {
        cout << "The strings are close." << endl;
    } else {
        cout << "The strings are not close." << endl;
    }

    return 0;
}
