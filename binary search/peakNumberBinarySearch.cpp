#include <bits/stdc++.h>
using namespace std;

/*
  LeetCode 162: Find Peak Element (O(log n) solution)

  A peak element is an element that is strictly greater than its neighbors.
  Given an integer array nums where nums[i] != nums[i+1], find any peak
  element and return its index. You may imagine nums[-1] and nums[n] are
  -∞, so an endpoint can also be a peak.

  This uses a binary-search–style approach:
    - At each step, compare nums[mid] with nums[mid+1].
    - If nums[mid] > nums[mid+1], you’re on a descending slope or at a peak,
      so a peak lies at or to the left ⇒ move high = mid.
    - Otherwise, you’re on an ascending slope ⇒ move low = mid + 1.
    - Loop continues while (low < high). When low == high, that index is a peak.
*/

class Solution {
public:
    int findPeakElement(const vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        // Narrow down the search window until low == high
        while (low < high) {
            // Safe midpoint calculation
            int mid = low + (high - low) / 2;

            // If we're descending, the peak is at mid or to the left
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            }
            // Otherwise the peak is to the right
            else {
                low = mid + 1;
            }
        }

        // low == high points to a peak element
        return low;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Read array size
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid array size\n";
        return 1;
    }

    vector<int> nums(n);
    // Read the elements
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int peakIndex = sol.findPeakElement(nums);

    // Output the index of any peak element
    cout << peakIndex << "\n";
    return 0;
}
