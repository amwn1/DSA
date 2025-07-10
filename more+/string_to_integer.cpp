#include <cstdlib> 
#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

class Solution {
public:
    
    string trim(string s) {
    int start = 0 ;
    int end = s.length() - 1;
    while(start <= end  ){
        if(!isspace(s[start]) && !isspace(s[end])) break ;
        if(isspace(s[start])) start ++;
        if(isspace(s[end])) end -- ;

    }
    return s.substr(start, end - start + 1);
    }
    
    int myAtoi(string s) {
    string trimString = trim(s);
    cout<< trimString << endl;
    long result = 0 ;
    bool isNegative = false;
    int i = 0;
    if(trimString[i] == '-'){
            isNegative = true ;
            i++ ;
        }
    while(isdigit(trimString[i]) || i < trimString.length()){
        
        if(!isdigit(trimString[i])) return (isNegative ? (int)-result : (int)result);
        else {
            result = result*10 + (trimString[i] - '0');
            i++;
        }
 
    }
    // cout << "This is the result"<< result << endl;
    
    return (isNegative ? (int)-result : (int)result);
    }
};

int main() {
    string s = "-04w5w2   ";
    
    // cout << s.length();
    Solution sol;  
    // cout << sol.trim(s) << endl;                     
    cout << sol.myAtoi(s) << endl;   
    return 0;
}
