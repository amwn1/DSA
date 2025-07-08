#include <iostream>
#include <vector>
using namespace std;

int binarySerach(vector<int> sortArray, int target){
int low = 0 ; int high = sortArray.size() - 1;

while(low <= high){
    int mid = low + (high - low)/2 ;
    if(target == sortArray[mid]){
        return mid ;
    }
    else if(target > sortArray[mid]){
       low = mid + 1 ; 
    }
    else{
       high = mid - 1;
    }
}
 return -1 ;

}

int main() {
    vector<int> sortArray = {2, 4, 6, 8, 10, 12, 14};
    int target = 1;
    int result = binarySerach(sortArray,target);
    if (result == -1){
        cout << "Elemnent not found";
    }
    else{
        cout<< "Element found at " << result ;
    }
    return 0;
}