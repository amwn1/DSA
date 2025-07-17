#include <iostream>
#include <string>
#include <set>
using namespace std;

/*
This program reverses only the vowels in a given string.
For example: "hello" becomes "holle"
*/

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Define a set of vowels (both lowercase and uppercase)
        set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U'};

        // Use two-pointer technique to swap vowels from both ends
        while (left < right) {
            // Move left pointer until a vowel is found
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }

            // Move right pointer until a vowel is found
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }

            // Swap the two vowels
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
