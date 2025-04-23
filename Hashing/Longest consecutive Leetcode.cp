#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sortedSet(nums.begin(), nums.end());
        int maxLength = 0;

        for (auto a : sortedSet) {
            if (sortedSet.find(a - 1) == sortedSet.end()) {
                int current = a;
                int count = 1;

                while (sortedSet.find(current + 1) != sortedSet.end()) {
                    current++;
                    count++;
                }

                maxLength = max(count, maxLength);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // Example test case
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = solution.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
