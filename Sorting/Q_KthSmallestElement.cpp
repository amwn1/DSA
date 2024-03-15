// There is an easy version where we just sort it out and take the kth element ,
// This one is using priority queue tho ;


#include <bits/stdc++.h>
using namespace std;
  
  int kSmall(vector<int> arr , int n , int k){
     priority_queue<int> prq;  
     for(int i = 0 ; i < k ; i++){ 
        prq.push(arr[i]);
     }
     for(int i = k ; i < n ; i++){
        prq.push(arr[i]);
        if(prq.size() > k){
            prq.pop();
        }
     }
     return prq.top();
  }
  
int main(){
   vector<int> arr = {5,20,34,53,12,2};
   int n = arr.size();
   int k = 2;
   cout << " The smallest element " << k << " is " << kSmall(arr , n , k);
}