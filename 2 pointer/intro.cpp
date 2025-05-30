// What is the two pointer techniquw ? 
// // Two Pointers is a method where you maintain two indices (or “pointers”) while iterating over a data structure, often to compare, combine, or partition data. The pointers can either:

// Move toward each other (from both ends)

// Move in the same direction, often with different speeds or condition

#include<iostream>
using namespace std ;
#include<vector>
void reverseArray(vector<int> &arr)
{
 int left = 0 ; 
 int right = arr.size() - 1;
 while(left < right){
    swap(arr[left],arr[right]);
    left++;
    right--;
 }
}
int main(){
vector<int> arr = {1,2,3,45,53};
for ( auto a : arr){
    cout << a << " ";
}
cout<< endl;
reverseArray(arr);
for ( auto a : arr){
    cout << a << " ";
}
}