#include <bits/stdc++.h>
using namespace std;

/*
  LeetCode 162: Find Peak Element

  A peak element is an element that is strictly greater than its neighbors.
  Given an integer array nums, find a peak element and return its index.
  If the array contains multiple peaks, return the index to any of the peaks.
  You may imagine that nums[-1] = nums[n] = -∞.

  Constraints:
    - Your solution must run in O(log n) or O(n) time.
    - You must return a valid index (0 <= index < n).
*/

class Solution {
public:
    int findPeakElement(const vector<int>& nums) {
        int n = nums.size();

        // Edge case: single element
        if (n == 1) 
            return 0;

        // Edge case: two elements — return index of the larger one
        if (n == 2) 
            return (nums[0] > nums[1] ? 0 : 1);

        // Scan the “interior” for a local peak:
        // any i in [1..n-2] such that nums[i] > nums[i-1] and nums[i] > nums[i+1].
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }

        // If no interior peak was found, then one of the ends must be a peak:
        // compare nums[0] vs. nums[n-1].
        return (nums[0] > nums[n - 1] ? 0 : n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Read the number of elements
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input size\n";
        return 1;
    }

    vector<int> nums(n);
    // Read the array elements
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int peakIndex = sol.findPeakElement(nums);

    // Output the index of any peak element
    cout << peakIndex << "\n";
    return 0;
}
