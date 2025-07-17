#include <iostream>
using namespace std;
string trim(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end) {
            if (!isspace(s[start]) && !isspace(s[end]))
                break;
            if (isspace(s[start]))
                start++;
            if (isspace(s[end]))
                end--;
        }
        return s.substr(start, end - start + 1);
    }
int main() {
    
    return 0;
}