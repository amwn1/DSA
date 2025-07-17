#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0; 
        int right = s.size() - 1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U'};
        
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--; 
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution sol;
    string result = sol.reverseVowels(input);

    cout << "Reversed vowels: " << result << endl;

    return 0;
}
