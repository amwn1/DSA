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
    int left = 0 ; 
    int right = nums.size() - 1; 
    int leftSum = nums[left] ; 
    int rightSum = nums[right] ;
    while (left<right)
    {
    if(leftSum < rightSum){
        left++;
        leftSum+= nums[left];
    }
    else if(rightSum > leftSum)
    {right--;
     rightSum += nums[right];
    }
    else 
    {left++;
      right--;
    }
    }
    return (leftSum == rightSum) ? right : -1;

    
    }
};

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    Solution sol;
    cout<< sol.pivotIndex(nums) << endl;
    return 0;
}