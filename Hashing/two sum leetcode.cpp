#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // value → index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // If complement exists in map, we found the answer
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }

        // Store current number with its index
        map[nums[i]] = i;
    }

    // If no pair found
    return {-1, -1};
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> result = twoSum(nums, target);
    cout << "Indices of elements that sum to " << target << " are: "
         << result[0] << " and " << result[1] << endl;

    return 0;
}
