#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std ;

int firstRepeatingElement(vector<int> &arr){
int answer = -1;
int minanswer = arr.size();
unordered_map <int,int> map ;

for(int i = 0 ; i < arr.size() ; i++){
    if(map.find(arr[i]) != map.end()){
        if(i<minanswer){
        minanswer = i ;
        answer = arr[i];
        }
    }
    else
    {
        map[arr[i]] = i ;
    }
}

return answer;

}

int main () {
    vector<int> arr = {1, 5, 3, 4, 3, 5, 6};
    int result = firstRepeatingElement(arr);
    cout << "The first occurence of the element is " << result << endl;
}
