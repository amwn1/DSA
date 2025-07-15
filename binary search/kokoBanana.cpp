#include <bits/stdc++.h>
using namespace std;

/*
Leetcode 875 – Koko Eating Bananas

Problem:
Koko has n piles of bananas, where piles[i] is the number of bananas in the i‑th pile.
She eats at a constant speed k bananas per hour. Each hour, she chooses one pile
and eats k bananas from it; if the pile has less than k bananas, she eats all of them
and stops for that hour. Given an integer h, the total number of hours she has,
find the minimum k such that she can eat all the bananas in h hours or less.

Approach:
Use binary search on the eating speed k:
 1. Set left = 1, right = max(piles).
 2. While left ≤ right:
    a. mid = (left + right) / 2 as candidate speed.
    b. Compute total hours needed at speed = mid:
       hours = sum( ceil(pile / mid) ) for each pile
            = sum( (pile + mid - 1) / mid ) using integer math.
    c. If hours > h, speed is too slow → left = mid + 1.
       Else      hours ≤ h, record answer = mid, try slower → right = mid - 1.
 3. Return the recorded answer.

Time Complexity: O(n log m), where n = number of piles, m = max pile size.
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long hours = 0;
            
            // Calculate hours needed at speed = mid
            for (int p : piles) {
                hours += (p + mid - 1) / mid;  // integer ceiling of p/mid
            }
            
            if (hours > h) {
                // Too slow: need higher speed
                left = mid + 1;
            } else {
                // Feasible: record and try slower speed
                answer = mid;
                right = mid - 1;
            }
        }
        
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    // Input:
    //   First line: n (number of piles) and h (hours available)
    //   Second line: n space‑separated integers for pile sizes
    if (!(cin >> n >> h)) {
        cerr << "Invalid input\n";
        return 1;
    }

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    Solution sol;
    int result = sol.minEatingSpeed(piles, h);
    cout << result << "\n";

    return 0;
}
