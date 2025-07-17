#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode Problem: Can Place Flowers
-----------------------------------
You are given a flowerbed (array of 0s and 1s), where:
- 0 means an empty plot
- 1 means a flower is already planted

You are also given an integer `n`, representing the number of new flowers to plant.
Rules:
- You cannot plant a flower in adjacent plots (no two 1s next to each other).
- Return true if `n` new flowers can be planted without violating the rule.

Example:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true (you can plant at index 2)

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false (only one spot available)
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sizeOfBed = flowerbed.size();
        int check = 0;

        // Check first position (i = 0)
        if (sizeOfBed >= 1 && flowerbed[0] == 0 && (sizeOfBed == 1 || flowerbed[1] == 0)) {
            flowerbed[0] = 1;
            check++;
        }

        // Check middle positions
        for (int i = 1; i < sizeOfBed - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                check++;
            }
            if (check >= n) return true;
        }

        // Check last position (i = sizeOfBed - 1)
        if (sizeOfBed >= 2 && flowerbed[sizeOfBed - 1] == 0 && flowerbed[sizeOfBed - 2] == 0) {
            flowerbed[sizeOfBed - 1] = 1;
            check++;
        }

        return check >= n;
    }
};

int main() {
    int n, bedSize;
    cout << "Enter number of plots in flowerbed: ";
    cin >> bedSize;

    vector<int> flowerbed(bedSize);
    cout << "Enter flowerbed (0s and 1s): ";
    for (int i = 0; i < bedSize; i++) {
        cin >> flowerbed[i];
    }

    cout << "Enter number of new flowers to plant: ";
    cin >> n;

    Solution sol;
    bool result = sol.canPlaceFlowers(flowerbed, n);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
