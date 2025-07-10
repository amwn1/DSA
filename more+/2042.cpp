#include <cstdlib> 
#include <iostream>
#include <string>
#include <cctype> 
#include <climits>
using namespace std;

bool areNumbersAscending(string s) {
    int i = 0 ; 
    int j = INT_MIN;
    while(i<s.length()){
        if(isdigit(s[i])){
        if(s[i] > j){
            j = s[i];
            
        }
        else{
            return false;
        }
        }
        i++ ;

    } 
    return true ;
    }


int main() {
    string s = "hello world 5 x 5";
    cout << areNumbersAscending(s) << endl;
    return 0;
}