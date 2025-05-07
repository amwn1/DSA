#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int>&heap, int index){
while(index > 0){
    int parent = (index-1)/2;
    if(heap[parent] < heap[index]){
        swap(heap[parent],heap[index]);
        index = parent;
    }
    else break;
    
}
}


void insert(vector<int>& heap,int a){
    heap.push_back(a);
    heapify(heap,heap.size()-1);
}

void print(vector<int> heap){
    for(auto a : heap){
        cout <<  " " << a << " " ;
    }
}

void heapifydown(vector<int> &heap, int index){
    while(index < heap.size()){
        int largest = index ;
        int leftchild = 2*index +1 ;
        int rightchild = 2*index +2;
        if (leftchild < heap.size() && heap[largest] < heap[leftchild]){
            
            largest = leftchild;
        }
        if (rightchild < heap.size() && heap[largest] < heap[rightchild]){
           
            largest = rightchild;
        }

        if(largest == index) break;
        swap(heap[index],heap[largest]);
        index = largest;

    }
}

void deletion(vector<int> & heap){
if(heap.empty()) return ;
heap[0] = heap.back();
heap.pop_back();
 heapifydown(heap,0);
}

int main(){
    vector<int> heap;
    insert(heap,20);
    insert(heap,12);
    insert(heap,23);
    insert(heap,15);
    print(heap);
    deletion(heap);
    cout<< endl;
    print(heap);
}