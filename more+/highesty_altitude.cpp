#include <bits/stdc++.h>
#include <climits>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAlt = 0;
        int currAlt = 0;
        for(int i=0 ; i < gain.size() ; i++){
          currAlt += gain[i];
          highestAlt  = max(currAlt,highestAlt);
        }
        return highestAlt;
    }
};

int main() {
    Solution sol;
    vector<int> gain = {44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81};
    cout << sol.largestAltitude(gain) << endl;
    return 0;
}