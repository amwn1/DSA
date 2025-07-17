#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sizeOfBed = flowerbed.size();
        int check = 0;

        if (sizeOfBed >= 1 && flowerbed[0] == 0 && (sizeOfBed == 1 || flowerbed[1] == 0)) {
            flowerbed[0] = 1;
            check++;
        }

        for (int i = 1; i < sizeOfBed - 1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                check++;
            }
            if (check >= n) return true;
        }

        if (sizeOfBed >= 2 && flowerbed[sizeOfBed - 1] == 0 && flowerbed[sizeOfBed - 2] == 0) {
            flowerbed[sizeOfBed - 1] = 1;
            check++;
        }

        return check >= n;
    }
};

int main() {
    int n, bedSize;
    cin >> bedSize;
    vector<int> flowerbed(bedSize);
    for (int i = 0; i < bedSize; i++) {
        cin >> flowerbed[i];
    }
    cin >> n;

    Solution sol;
    bool result = sol.canPlaceFlowers(flowerbed, n);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
