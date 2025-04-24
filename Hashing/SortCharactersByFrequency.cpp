#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> vfreq(freq.begin(), freq.end());

        sort(vfreq.begin(), vfreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;  // sort descending by frequency
        });

        string ans;
        for (auto [ch, count] : vfreq) {
            ans += string(count, ch);  // append character 'count' times
        }

        return ans;
    }
};

int main() {
    Solution solution;

    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = solution.frequencySort(input);
    cout << "Sorted by frequency: " << result << endl;

    return 0;
}
