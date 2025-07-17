#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int sizeWord1 = word1.size();
        int sizeWord2 = word2.size();
        int minSize = min(sizeWord1, sizeWord2);
        for (int i = 0; i < minSize; i++) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        if (sizeWord1 > sizeWord2) {
            for (int i = minSize; i < sizeWord1; i++) {
                ans.push_back(word1[i]);
            }
        } else {
            for (int i = minSize; i < sizeWord2; i++) {
                ans.push_back(word2[i]);
            }
        }
        return ans;
    }
};

int main() {
    string word1, word2;
    cin >> word1 >> word2;

    Solution sol;
    string result = sol.mergeAlternately(word1, word2);
    cout << result << endl;

    return 0;
}
