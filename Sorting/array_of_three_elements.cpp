// Q_3 types of elements are given . to sort out unlike two arrays before we might be given an range[5,10],0,1,2,and more
// A -> Dutch national Flag Algorithm (A type of hoar's partition )

#include<iostream>
using namespace std ;

void dnf(int arr[],int n){
int low = 0 ;
int mid = 0;
int high = n-1;

while(mid <= high)
{
if(arr[mid] == 0){
    swap(arr[low],arr[mid]);
    low++;
    mid++;
}
else if(arr[mid] == 1){
    mid++;
}
else{
    swap(arr[mid],arr[high]);
    high--;
}
}
}

int main(){
    int arr[]= {0,0,2,1,0,2,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    dnf(arr , n );
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}