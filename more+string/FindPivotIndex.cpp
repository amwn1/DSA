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
int pivotIndex(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(),nums.end(),0);
    int leftSum = 0 ;
    int rightsum = 0 ;
    for(int i = 0 ; i < nums.size();i++){
        rightsum = totalSum - leftSum - nums[i];
        if(rightsum == leftSum) return i ;
        leftSum+= nums[i];
    }
    return -1;
}     
};

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    Solution sol;
    cout<< sol.pivotIndex(nums) << endl;
    return 0;
}