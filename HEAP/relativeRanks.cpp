#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        vector<string> result(n);
        int rank = 1;

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        while (!pq.empty()) {
            int index = pq.top().second;
            pq.pop();

            if (rank == 1) result[index] = "Gold Medal";
            else if (rank == 2) result[index] = "Silver Medal";
            else if (rank == 3) result[index] = "Bronze Medal";
            else result[index] = to_string(rank);

            rank++;
        }

        return result;
    }
};

int main() {
    vector<int> scores = {10, 3, 8, 9, 4};
    Solution sol;
    vector<string> ranks = sol.findRelativeRanks(scores);

    cout << "Relative ranks: ";
    for (const string& r : ranks) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}