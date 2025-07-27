#include <iostream>
#include <vector>
using namespace std;

// This Solution class finds if there is an increasing triplet subsequence
// in an array (three numbers i<j<k with nums[i] < nums[j] < nums[k])
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // If there are less than 3 numbers, no triplet is possible
        if(nums.size() < 3) return false;
        // For each possible starting index
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            bool MiddleElementFound = false; // Flag if a "middle" has been found yet
            int middleElement = 0; // Stores the middle value in the sequence
            // Scan all following elements
            while(j < nums.size()) {
                if(MiddleElementFound) {
                    // If a better (smaller) "middle" but still > nums[i], update it
                    if(nums[j] < middleElement && nums[j] > nums[i]) {
                        middleElement = nums[j];
                    }
                    // If found three increasing numbers: nums[i] < middleElement < nums[j]
                    if(middleElement < nums[j]) {
                        return true;
                    }
                } else {
                    // Set the first possible "middle" if nums[j] > nums[i]
                    if(nums[i] < nums[j]) {
                        middleElement = nums[j];
                        MiddleElementFound = true;
                    }
                }
                j++;
            }
        }
        // No triplet found
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 5, 0, 4, 1, 3};
    vector<int> test2 = {5, 4, 3, 2, 1};
    vector<int> test3 = {1, 2, 3, 4, 5};

    cout << boolalpha;
    cout << "Test 1 (should be true): " << sol.increasingTriplet(test1) << endl;
    cout << "Test 2 (should be false): " << sol.increasingTriplet(test2) << endl;
    cout << "Test 3 (should be true): " << sol.increasingTriplet(test3) << endl;

    /*
      Dry run on test1:
      i=0 (nums=1), finds middle=5, doesn't find third; i=2 (nums=0) finds middle=4, then 1, then: 1<3, triplet found!
    */

    return 0;
}
