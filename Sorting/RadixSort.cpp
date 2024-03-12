// Counting Sort 
// counting sort takes bigo(o+n)
// Radix Sort works in a linear way , it is not a comparison based algo like counting sort

// NOTE:
// small range 
// all the numbers should have same number of digits

// 319 , 212 , 6, 8, 100 , 50 
// will add the 0s to make them all 3 digits 
// -> 319 ,212, 006 , `100 , 050

// The we will sort them from the last digit (less significant digit) -> middle digit -> most significant digit (using stable sot for all of them)

//  100 , 050 , 212 , 006 , 008 , 319 : Note the last digits are sorted
//  100 , 006 , 008 , 212 , 319 , 050 : Note the middle digits are sorted 
//  006 , 008 , 050 , 100 , 212 , 319 : Now all the array is sorted ( last -> middle ->first)

// Time complexity => theta(d*(n+b))
// Space complexity => theta(n+b)

#include <iostream>

using namespace std;

void countSort( int arr[] , int n , int exp){
     int count[10] , output[n];
     for(int i = 0 ; i < 10 ; i++ ) { count[i] = 0 ;}
     for(int i = 0 ; i < n; i++) {
         count[(arr[i]/exp)%10]++;
     }
     
     for(int i = 1 ; i < 10 ; i++){
         count[i] = count[i-1] + count[i];
     }
     
     for(int i = n-1 ; i >= 0 ; i--) {
         output[count [(arr[i]/exp)%10] - 1] = arr[i];
         count[(arr[i]/exp)%10] -- ;
     }
        
     for( int i = 0 ; i < n ; i++){
         arr[i] = output[i];
     }
     
 }
 
 void radixSort( int arr[] , int n){
     int mx = arr[0] ;
     for(int i = 1 ; i < n ; i++){
         if(arr[i]> mx) mx = arr[i];
     }
     for(int exp = 1 ; mx/exp > 0 ; exp*=10 ){
         countSort( arr , n , exp);
     }
 }
 
 
 
 int main(){
    
    int arr[] = {1,4,4,1,0,1};
    int n = 6;
    radixSort( arr, n );
    for(int i = 0 ; i < n ; i++){
         cout << arr[i]<< " ";
     }

}
