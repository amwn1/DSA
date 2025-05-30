#include<iostream>
#include<vector>
using namespace std;

int removeduplicates(vector<int> &arr){
if(arr.empty()) return 0;

int i = 0 ;
for(int j = 1 ; j < arr.size() ; j++){
    if(arr[i] != arr[j]){
        i++;
        arr[i] = arr[j];
    }
}
return i + 1;

}

int main(){
 vector<int> arr = {1,1,2,2,4,4,51,23};
 int size = removeduplicates(arr);
 for ( int i = 0 ; i < size ; i++){
    cout << arr[i] << " " ;
 }
}
