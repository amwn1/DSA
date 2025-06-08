#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // min-heaps for the “first” and “last” candidate pools
        priority_queue<int, vector<int>, greater<int>> firstPq, lastPq;

        int n = costs.size();
        int take = min(candidates, n);

        // fill the first pool
        for (int i = 0; i < take; i++) {
            firstPq.push(costs[i]);
        }
        // fill the last pool
        for (int i = max(take, n - take); i < n; i++) {
            lastPq.push(costs[i]);
        }

        int left = take; 
        int right = n - take - 1;
        long long sum = 0;

        // pick k times
        for (int i = 0; i < k; i++) {
            // prefer from firstPq if it's smaller (or last is empty)
            if (lastPq.empty() || (!firstPq.empty() && firstPq.top() <= lastPq.top())) {
                sum += firstPq.top();
                firstPq.pop();
                if (left <= right) {
                    firstPq.push(costs[left++]);
                }
            } else {
                sum += lastPq.top();
                lastPq.pop();
                if (left <= right) {
                    lastPq.push(costs[right--]);
                }
            }
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    int k, candidates;
    cin >> k >> candidates;

    Solution sol;
    cout << sol.totalCost(costs, k, candidates) << "\n";

    return 0;
}
