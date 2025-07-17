#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(int i = 0 ; i < candies.size() ; i++) {
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
    cin >> n;
    vector<int> candies(n);
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }
    cin >> extraCandies;

    Solution sol;
    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    for (bool val : result) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
