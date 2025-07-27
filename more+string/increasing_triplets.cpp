#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        for (int x : nums) {
            if (x <= smallest) {
                smallest = x;
            } else if (x <= secondSmallest) {
                secondSmallest = x;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5},    // true
        {5, 4, 3, 2, 1},    // false
        {2, 1, 5, 0, 4, 6}, // true
        {1},                // false
        {1, 1, 1, 1},       // false
        {1, 5, 0, 4, 1, 3}  // true
    };

    for (int i = 0; i < tests.size(); ++i) {
        cout << "Test " << i + 1 << ": ";
        cout << boolalpha << solution.increasingTriplet(tests[i]) << endl;
    }
    return 0;
}
