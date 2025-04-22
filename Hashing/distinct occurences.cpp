#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> map;
    unordered_set<int> set;

    for (auto a : arr) {
        map[a]++;
    }

    for (auto p : map) {
        if (set.find(p.second) != set.end()) {
            return false;
        }
        set.insert(p.second);
    }

    return true;
}

int main() {
    // Example 1
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    if (uniqueOccurrences(arr)) {
        cout << "The number of occurrences are unique." << endl;
    } else {
        cout << "Duplicate frequencies found." << endl;
    }

    return 0;
}
