#include <cstdlib> 
#include <iostream>
#include <string>
#include <cctype> 
#include <climits>
using namespace std;

bool areNumbersAscending(string s) {
        int k = 0;
        int j = INT_MIN;
        int digit = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                digit = digit * 10 + (s[i] - '0');
                continue;
            }
            if (digit != 0) {
                k = digit;
                digit = 0;

                if (j < k)
                    j = k;
                else
                    return false;
            }
        }
        if(digit != 0 ){
            k = digit ;
            if(j<k) j = k ;
            else return false;
        }

        return true;
    }


int main() {
    string s = "hello world 5 x 5";
    cout << areNumbersAscending(s) << endl;
    return 0;
}