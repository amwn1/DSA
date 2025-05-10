#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>  // For reverse

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequency of each element
        for (auto num : nums) {
            mp[num]++;
        }

        // Min heap to keep top k frequent elements: {frequency, number}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : mp) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract result from heap
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        // Reverse to get most frequent first (optional)
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
