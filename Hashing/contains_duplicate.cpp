#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to check for duplicates using hashmap
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end()) {
            return true;  // Duplicate found
        }
        map[nums[i]] = i;  // Store number with its index
    }

    return false;  // No duplicates
}

int main() {
    // Test input
    vector<int> nums = {1, 2, 3, 4, 1};

    // Call the function
    bool result = containsDuplicate(nums);

    // Output the result
    if (result)
        cout << "Duplicate found!" << endl;
    else
        cout << "All elements are unique." << endl;

    return 0;
}
