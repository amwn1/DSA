#include <iostream>
using namespace std;

class Solution {
public:
    int ans = 0 ; 

    int climbStairs(int n) {
        if(n == 1) return 1 ;
        
        return ans ;
    }
};

int main() {
    int n = 3 ;
    Solution sol;

    sol.climbStairs(n);
    return 0;
}