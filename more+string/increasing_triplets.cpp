#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            bool MiddleElementFound = false;
            int middleElement = 0;
            while(j < nums.size()) {
                if(MiddleElementFound) {
                    if(nums[j] < middleElement && nums[j] > nums[i]) {
                        middleElement = nums[j];
                    }
                    if(middleElement < nums[j]) {
                        return true;
                    }
                } else {
                    if(nums[i] < nums[j]) {
                        middleElement = nums[j];
                        MiddleElementFound = true;
                    }
                }
                j++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> test1 = {1, 5, 0, 4, 1, 3};
    vector<int> test2 = {5, 4, 3, 2, 1};
    vector<int> test3 = {1, 2, 3, 4, 5};
    cout << boolalpha;
    cout << "Test 1: " << sol.increasingTriplet(test1) << endl; // true
    cout << "Test 2: " << sol.increasingTriplet(test2) << endl; // false
    cout << "Test 3: " << sol.increasingTriplet(test3) << endl; // true
    return 0;
}
