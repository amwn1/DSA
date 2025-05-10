#include <iostream>
#include <vector>
#include <queue>  // For priority_queue
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap of size k
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main() {
    // Example test case
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution sol;
    int result = sol.findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
