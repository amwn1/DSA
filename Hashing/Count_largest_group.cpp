#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> map;
        int maxfreq = -1; 
        int count = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0, temp = i;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            map[sum]++;
        }

        for (auto it : map) {
            int freq = it.second;
            maxfreq = max(maxfreq, freq);
        }

        for (auto it : map) {
            int freq = it.second;
            if (freq == maxfreq) count++;
        }

        return count;
    }
};

int main() {
    Solution solution;

    int n = 13; // sample input
    int result = solution.countLargestGroup(n);

    cout << "Number of groups with the largest size: " << result << endl;

    return 0;
}
