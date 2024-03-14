// Bucket Sort works on thefloating point numbers between range 0.0 to 1.0 
// Non comparison based Algo 
// inputs should be uniformly and independently distrubuted across[0,1] to get a running time of O(n)
// Data should beuniformly distrributed . then it is not a great algorithm , we use insertion sort as well for the each individual bucket
// say in a example
// IP : arr[] = {20 , 80 , 10 , 85 , 75 , 99 , 18} , k=5
// k is the number of buckets 
// Q_ How to set range?
// A_ We will assume the lower no. to be 0 and the highest to be the max of the array 

// How this works ->
// Take the range -> Sort them in individual bucket -> Concatenate them in the end 

#include<iostream>
#include <vector>
using namespace std;
#include <algorithm>

void bucketSort( int arr[] , int n , int k){
int max = arr[0];
for(int i = 1 ; i < n ; i++ ){
    if(arr[i]>max) arr[i] = max;
}
max++; // we do this to allovate the write bucketInteger as if 80 is evaluate then it will come in the
//  5th place (4th) where our buckets are say 4 (0 , 1,2,3,4)

vector<int> bucket[k];

for(int i = 0 ; i < n ; i++){
    int bucketInteger = ((arr[i]*k)/max) ; // kind of an important part to remember 
    bucket[bucketInteger].push_back(arr[i]); 
}

for( int i = 0 ; i < k ; i++){
    sort(bucket[i].begin(), bucket[i].end());
}

int index  = 0 ;
for(int j = 0 ; j < k ; j++){
    for(int i = 0 ; i < bucket[j].size() ; i++){
        arr[index] = bucket[j][i];
        index++;
    }
}

}

int main(){
    
    int arr[] = {30,40,10,80,5,12,70};
    int k = 4;
    int n = 7;
    bucketSort( arr , n , k );
    for(int i = 0 ; i < n ; i++){
         cout<<arr[i]<<" ";
     }

}

// ************ TIME AND SPACE COMPLEXITY **************
// Time complexity
// Assuming k is approximetely equal to the number

// BEST CASE : Data is uniformly distributed
// O(n)
// // We use the inserstion sort because its the best algo for smaller numbers

// WORST CASE : Everything goes into a single bucket 
// If insertion sort is used O(n^2)

// though an algo of n(log*n) is used , it wont be feasible for the best case 

// SO bucket sort is optimally used when the elements are evenly seperated !