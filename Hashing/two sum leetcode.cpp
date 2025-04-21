class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> map;
            for (int i = 0 ; i< nums.size() ; i++){
                 map[nums[i]] = i;
                int complement = target - nums[i];
    
                if( map.find(complement) != map.end()){
                    return {map[complement],i};
                }
    
               
            }
            return {-1,-1};
        }
    };