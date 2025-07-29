#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 0) return 0;
        int count = 1;
        int point = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || chars[i] != chars[i + 1]) {
                if (count <= 1) {
                    chars[point] = chars[i];
                    point++;
                } else {
                    chars[point] = chars[i];
                    point++;
                    string stringcount = to_string(count);
                    for (char digits : stringcount) {
                        chars[point] = digits;
                        point++;
                    }
                    count = 1;
                }
            } else {
                count++;
            }
        }
        return point;
    }
};

int main() {
    Solution sol;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    cout << "Original array: ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;
    
    int new_length = sol.compress(chars);
    
    cout << "New length: " << new_length << endl;
    cout << "Modified array (first " << new_length << " elements): ";
    for (int i = 0; i < new_length; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    
    return 0;
}
