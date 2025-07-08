#include <iostream>
#include <vector>
using namespace std;

// Binary Search function
int binarySerach(vector<int> sortArray, int target) {
    int low = 0;                            // Start index of search space
    int high = sortArray.size() - 1;        // End index of search space

    // Loop until search space becomes invalid
    while (low <= high) {
        // Prevents overflow and calculates the middle index safely
        int mid = low + (high - low) / 2;

        // If the middle element matches the target, return the index
        if (target == sortArray[mid]) {
            return mid;
        }
        // If target is greater than the mid element, search in right half
        else if (target > sortArray[mid]) {
            low = mid + 1;
        }
        // If target is less than the mid element, search in left half
        else {
            high = mid - 1;
        }
    }

    // If element is not found, return -1
    return -1;
}

int main() {
    vector<int> sortArray = {2, 4, 6, 8, 10, 12, 14};  // Must be sorted
    int target = 1;                                    // Target to find
    int result = binarySerach(sortArray, target);      // Perform search

    if (result == -1) {
        cout << "Element not found";                   // If not found
    } else {
        cout << "Element found at " << result;         // If found
    }

    return 0;
}

/*
🧪 DRY RUN of Binary Search
----------------------------

Input array: [2, 4, 6, 8, 10, 12, 14]
Target: 1

Step 1:
  low = 0, high = 6
  mid = 0 + (6 - 0) / 2 = 3
  sortArray[3] = 8
  Since 1 < 8 → high = mid - 1 = 2

Step 2:
  low = 0, high = 2
  mid = 0 + (2 - 0) / 2 = 1
  sortArray[1] = 4
  Since 1 < 4 → high = mid - 1 = 0

Step 3:
  low = 0, high = 0
  mid = 0 + (0 - 0) / 2 = 0
  sortArray[0] = 2
  Since 1 < 2 → high = mid - 1 = -1

Exit loop: low > high → return -1

Conclusion:
Target 1 is not present in the array.
Output: "Element not found"

*/
