#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// This class checks if there is an increasing triplet subsequence
// (three numbers i < j < k with nums[i] < nums[j] < nums[k])
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // If there are less than 3 numbers, it's impossible
        if (nums.size() < 3) return false;

        int smallest = INT_MAX;        // Tracks the smallest so far
        int secondSmallest = INT_MAX;  // Tracks the second smallest in pattern

        for (int x : nums) {
            if (x <= smallest) {
                // Update smallest if we find a new lower value
                smallest = x;
            } else if (x <= secondSmallest) {
                // Update secondSmallest if x is between smallest and secondSmallest
                secondSmallest = x;
            } else {
                // If x is greater than both, we found our triplet
                return true;
            }
        }
        // No increasing triplet found
        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5},    // true: e.g. 1,2,3 (or any longer increasing pattern)
        {5, 4, 3, 2, 1},    // false: strictly decreasing
        {2, 1, 5, 0, 4, 6}, // true: 1,4,6 or 0,4,6 etc
        {1},                // false: less than 3 numbers
        {1, 1, 1, 1},       // false: all same number
        {1, 5, 0, 4, 1, 3}  // true: 0,1,3
    };

    for (int i = 0; i < tests.size(); ++i) {
        cout << "Test " << i + 1 << ": ";
        cout << boolalpha << solution.increasingTriplet(tests[i]) << endl;
    }

    /*
    You can try adding more vectors to test different scenarios.
    The output will be 'true' if an increasing triplet exists, and 'false' otherwise.
    */
    return 0;
}
