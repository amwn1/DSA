#include <bits/stdc++.h>
using namespace std;

/*
  LeetCode 374: Guess Number Higher or Lower

  Problem:
    I pick a number 'pick' between 1 and n. You have to guess which number I picked.
    Each time you call guess(x), it returns:
      -1 : my number is lower than x
      +1 : my number is higher than x
       0 : you guessed correctly

    Implement guessNumber(n) to find 'pick' in O(log n) calls.

  Core idea:
    Perform a binary search over the range [1..n]:
      - Maintain low and high bounds.
      - At each step, probe mid = low + (high - low)/2 (overflow-safe).
      - Use the guess API feedback to discard half the search space.
*/

/// You can simulate the hidden pick here for local testing:
static int pick = 0;

/// Stub of the guess API. In LeetCode this is provided; here we implement it.
int guess(int num) {
    if (num == pick) return 0;
    return (num < pick) ? +1 : -1;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        // Standard binary search loop
        while (low <= high) {
            // Compute mid in an overflow-safe way:
            //   (low + high) might overflow for large ints,
            //   so we do low + (high - low)/2 instead.
            int mid = low + (high - low) / 2;

            int res = guess(mid);
            if (res == 0) {
                // Found the correct number
                return mid;
            }
            else if (res < 0) {
                // Our guess was too high, so reduce the upper bound
                high = mid - 1;
            }
            else {
                // Our guess was too low, so raise the lower bound
                low = mid + 1;
            }
        }

        // Should never reach here if pick is guaranteed to be in [1..n]
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter n (upper bound): ";
    cin >> n;

    cout << "Enter the hidden number to pick (between 1 and " << n << "): ";
    cin >> pick;

    Solution sol;
    int guessed = sol.guessNumber(n);

    if (guessed != -1) {
        cout << "Correctly guessed: " << guessed << "\n";
    } else {
        cout << "Error: could not guess the number.\n";
    }

    return 0;
}
