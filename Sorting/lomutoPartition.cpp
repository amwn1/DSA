// Q_ Is that we need to seperate two kinds of elements in an array wether it be binary , odd or even,  +ve or -ve
// We can do this by Quick sort Lomuto or Hoarse partition , Here I choose to do Lomuto 

#include <iostream>
using namespace std ;

void quickSort(int arr[],int n){
    int i = - 1; 
    int j = n ;
    while(true){
        do{i++;} while(arr[i] == 0);
        do{j--;} while(arr[j] != 0);
        if(i>=j)
        return ;
        swap(arr[i],arr[j]);
    }
}

int main(){
    int arr [] = {0,1,1,1,0,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr , n );
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i] << " ";
    }
}