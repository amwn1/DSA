#include <iostream>
using namespace std;

void intersection(int a[], int b[], int m, int n){

int i = 0 ; int j = 0 ;

while(i < m && j < n){
    if(i > 0 && a[i] == a[i-1]){i++; continue;}
    if(a[i] > b[j]) { j++; }
    else if(a[i] < b[j]) {i++;}
    else {cout << a[i] << " " ; i++ ; j++;}
}

}

void naive_intersection(int arr1[], int arr2[] , int n1 , int n2){
    for(int i = 0 ; i < n1 ; i++)
    {
        if(i>0 && arr1[i]==arr1[i-1]){
            continue;
        }
        for(int j = 0 ; j < n2 ; j++){
            if(arr1[i] == arr2[j]){
                cout<<arr2[j]<<" ";
                break;
            }
        }
    }
}

int main() {
    int array1[5] = {1, 20, 20, 40, 60};
    int array2[4] = {2, 20, 20, 20};

    // naive_intersection(array1, array2, 5, 4) ;

    intersection(array1 , array2 , 5, 4);

}