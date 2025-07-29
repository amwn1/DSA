#include <iostream>
#include <vector>
#include <string>

using namespace std;

// I implemented this Solution class for LeetCode problem 443: "String Compression".
// Question Number: 443
// Question Title: String Compression
// URL: https://leetcode.com/problems/string-compression/
class Solution {
public:
    // My function compresses a vector of chars in-place and returns the new length.
    // Problem Description (as on LeetCode): Given an array of characters chars, compress it using the following algorithm:
    // Begin with an empty string s. For each group of consecutive repeating characters in chars:
    // - If the group's length is 1, append the character to s.
    // - Otherwise, append the character followed by the group's length.
    // The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
    // Note that group lengths that are 10 or longer will be split into multiple characters in chars.
    // After you are done modifying the input array, return the new length of the array.
    // You must write an algorithm that uses only constant extra space.
    // Constraints: 1 <= chars.length <= 2000; chars[i] is a lowercase letter, uppercase letter, digit, or symbol.
    // Examples:
    // - Input: ["a","a","b","b","c","c","c"] → Output: 6, modified array: ["a","2","b","2","c","3"]
    // - Input: ["a"] → Output: 1, modified array: ["a"]
    // - Input: ["a","b","b","b","b","b","b","b","b","b","b","b","b"] → Output: 4, modified array: ["a","b","1","2"]
    // My Approach and Logic: I use a single for-loop with a write pointer ('point') to modify the array in-place.
    // I track consecutive repeats with 'count'. At the end of each group (when the next char differs or we reach the end),
    // I write the char, and if count > 1, I convert count to a string using to_string and write each digit.
    // I reset count after each group. This handles multi-digit counts automatically (e.g., 12 becomes '1' and '2').
    // Time Complexity: O(n) - The loop runs n times, with constant work per group.
    // Space Complexity: O(1) - Only fixed variables and a small temporary string; no extra space growing with n.
    int compress(vector<char>& chars) {
        int n = chars.size();  // I store the array size for easy access.
        if (n == 0) return 0;  // I handle the empty array edge case by returning 0 immediately.
        
        int count = 1;  // I start count at 1 since every group has at least one char.
        int point = 0;  // This is my write pointer—I use it to track where to place the next char or digit in the array.
        
        // I loop through the array from index 0 to n-1.
        for (int i = 0; i < n; i++) {
            // I check for the end of a group: if it's the last element or the next char is different.
            // I put the end-of-array check first to avoid out-of-bounds errors.
            if (i == n - 1 || chars[i] != chars[i + 1]) {
                // For groups of size 1, I just write the char and move on.
                if (count <= 1) {
                    chars[point] = chars[i];  // I write the single char here.
                    point++;  // I increment the pointer after writing.
                } else {
                    // For larger groups, I first write the char.
                    chars[point] = chars[i];
                    point++;
                    
                    // I convert the count to a string to handle any number of digits.
                    string stringcount = to_string(count);
                    
                    // I loop through each digit in the string and write it to the array.
                    // This way, multi-digit counts (e.g., 12) get split into separate chars ('1', '2').
                    for (char digits : stringcount) {
                        chars[point] = digits;
                        point++;
                    }
                    
                    count = 1;  // I reset the count here for the next group.
                }
            } else {
                // If the next char is the same, I just increment the count.
                count++;
            }
        }
        // I return 'point' as the new length—it's exactly where the compressed data ends.
        return point;
    }
};

// This main function is for local testing in my repo—you can run it to see the code in action.
int main() {
    Solution sol;  // I create a Solution instance.
    
    // Sample test case I use for demo: a mix of consecutive groups.
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    // I print the original array to show before/after.
    cout << "Original array: ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;
    
    // I call compress and store the new length.
    int new_length = sol.compress(chars);
    
    // I print the results to verify.
    cout << "New length: " << new_length << endl;
    cout << "Modified array (first " << new_length << " elements): ";
    for (int i = 0; i < new_length; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;
    
    // In my tests, this input compresses to 'a 2 b 2 c 3' with length 6.
    // Feel free to swap in other test cases, like {'a','b','b','a'} for 'a b 2 a' (length 4).
    
    return 0;
}
