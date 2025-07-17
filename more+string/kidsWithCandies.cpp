#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
LeetCode Problem: Kids With the Greatest Number of Candies
-----------------------------------------------------------
There are n kids with candies. You are given an integer array candies, 
where each candies[i] represents the number of candies the i-th kid has, 
and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after 
giving the i-th kid all the extraCandies, they will have the greatest number of 
candies among all the kids, or false otherwise.

Example:
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

Explanation:
Kid 0 → 2 + 3 = 5 ≥ max(5) → true
Kid 1 → 3 + 3 = 6 ≥ max(5) → true
Kid 2 → 5 + 3 = 8 ≥ max(5) → true
Kid 3 → 1 + 3 = 4 < max(5) → false
Kid 4 → 3 + 3 = 6 ≥ max(5) → true
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(), candies.end());
        vector<bool> ans;

        // Check for each kid
        for(int i = 0 ; i < candies.size() ; i++) {
            // If after adding extraCandies, the kid's candy count is >= maxCandy
            if((candies[i] + extraCandies) >= maxCandy) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};

int main() {
    int n, extraCandies;
    cout << "Enter number of kids: ";
    cin >> n;

    vector<int> candies(n);
    cout << "Enter candies for each kid: ";
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }

    cout << "Enter extra candies: ";
    cin >> extraCandies;

    Solution sol;
    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    for (bool val : result) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
