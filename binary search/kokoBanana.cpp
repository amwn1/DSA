#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(), piles.end());
        int ans = j;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid;
            }
            if (hours > h) {
                i = mid + 1;
            } else {
                ans = mid;
                j = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    // Input format:
    // First line: n (number of piles) and h (hours)
    // Second line: n space-separated integers (pile sizes)
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
