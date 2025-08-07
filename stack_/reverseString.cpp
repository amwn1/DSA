#include <stack>  // For stack
#include <vector>  // For vector<char> as input
using namespace std;

// LeetCode class format
class Solution {
public:
    void reverseString(vector<char>& s) {
        // Your logic: Check if empty, then use stack to reverse via LIFO
        // Step 1: Handle empty case (though LeetCode inputs are vector, we simulate)
        if (s.empty()) {
            return;  // Nothing to do, like printing "Empty" in local version
        }
        
        // Step 2: Create stack and push each char (O(n) time)
        stack<char> myStack;
        for (char a : s) {
            myStack.push(a);  // Bottom: first chars, top: last chars
        }
        
        // Step 3: Get size for loop (smart, as size changes on pop)
        int n = myStack.size();
        
        // Step 4: Pop and overwrite the original vector in-place
        // Builds the reversal by assigning popped tops back to s
        for (int i = 0; i < n; i++) {
            s[i] = myStack.top();  // Assign to s[i] (starts with last char)
            myStack.pop();
        }
        
        // Dry run example (like your "hellol"): s = ['h','e','l','l','o','l']
        // Push: stack = ['h','e','l','l','o','l'] (top 'l')
        // n=6
        // Loop: s[0]='l' (pop 'l'), s[1]='o' (pop 'o'), s[2]='l' (pop 'l'),
        //       s[3]='l' (pop 'l'), s[4]='e' (pop 'e'), s[5]='h' (pop 'h')
        // Result: s = ['l','o','l','l','e','h']  // "lolleh"
        
        // Time Complexity: O(n) - One loop to push n chars, one to pop/assign n chars
        // Space Complexity: O(n) - Stack holds n chars (extra space)
        // Note: For LeetCode optimal (O(1) space), use two pointers: swap from ends without stack.
        // But this nails stack basics—try the pointer way next for comparison!
    }
};
