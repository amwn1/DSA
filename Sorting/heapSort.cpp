 #include <iostream>
using namespace std;
  
  void heapify(int arr[], int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) { 
        max = left;
    }
    if (right < n && arr[right] > arr[max]) { 
        max = right;
    }

    if (max != i) {
        swap(arr[max], arr[i]);
        heapify(arr, n, max);
    }
}
    
    void heapsort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Heap sort
    for (int size = n - 1; size > 0; size--) {
        swap(arr[0], arr[size]); // Move current root to end
        heapify(arr, size, 0); // Ensure the heap property is maintained
    }
}

int main(){
    int arr[] = {12,34,21,52,63,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }
    
    heapsort(arr,n);
    
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    
}