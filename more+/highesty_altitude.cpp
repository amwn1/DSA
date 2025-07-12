// Leetcode 1732: Find the Highest Altitude
// --------------------------------------------------------
// You're given a list of net gains/losses in altitude after each point of a bike trip.
// The biker starts at altitude 0.
// The altitude at the i-th point is the sum of gains[0] to gains[i - 1].
// Your task is to return the highest altitude reached during the trip.
// --------------------------------------------------------

#include <bits/stdc++.h>        // Includes all standard headers
#include <climits>             // For INT_MAX, INT_MIN
#include <vector>              // For using vectors
#include <string>              // For string operations
#include <unordered_map>       // Hash map
#include <map>                 // Ordered map
#include <algorithm>           // For max(), sort(), etc.

using namespace std;

class Solution {
public:
    // Function to compute the highest altitude reached
    int largestAltitude(vector<int>& gain) {
        int highestAlt = 0;   // Stores the maximum altitude reached
        int currAlt = 0;      // Current altitude starts from 0

        // Iterate through each gain value in the input vector
        for (int i = 0; i < gain.size(); i++) {
            currAlt += gain[i];                      // Apply the gain/loss to current altitude
            highestAlt = max(currAlt, highestAlt);   // Update the highest altitude so far
        }

        return highestAlt;  // Return the final highest altitude reached
    }
};

int main() {
    Solution sol;

    // Sample test case: each value is the gain/loss at that step
    vector<int> gain = {
        44, 32, -9, 52, 23, -50, 50, 33, -84, 47,
        -14, 84, 36, -62, 37, 81, -36, -85, -39, 67,
        -63, 64, -47, 95, 91, -40, 65, 67, 92, -28,
        97, 100, 81
    };

    // Call the function and print the result
    cout << sol.largestAltitude(gain) << endl;

    return 0;
}
