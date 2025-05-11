#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int a : stones) {
            pq.push(a);
        }

        while (pq.size() >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            if (a != b) {
                pq.push(a - b);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1}; // sample input
    Solution sol;
    int result = sol.lastStoneWeight(stones);
    
    cout << "Last remaining stone weight: " << result << endl;

    return 0;
}
