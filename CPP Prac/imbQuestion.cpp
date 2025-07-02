
#include <iostream>

int ibm(int n){
    int sum = 0 ;
    for(int i = n-1 ; i > 0 ; i-- ){
        sum+= i*5;
    }
    return sum + 1;

}

int main() {
    int n = 4;
    std:: cout << ibm(n) ;
} 