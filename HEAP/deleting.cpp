#include <iostream>
#include <vector>
using namespace std;

// "bubble down" helper: restores min-heap property from index downwards
void heapifyDown(vector<int>& heap, int index) {
    int size = heap.size();
    while (index < size) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Compare with left child
        if (leftChild < size && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        // Compare with right child
        if (rightChild < size && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // If the current node is already the smallest, heap property holds
        if (smallest == index)
            break;

        // Otherwise, swap downwards and continue
        swap(heap[index], heap[smallest]);
        index = smallest;
    }
}

// "bubble up" helper: restores min-heap property from index upwards
void heapifyUp(vector<int>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        // If child is smaller than parent, swap and continue upwards
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            // Heap property satisfied
            break;
        }
    }
}

// Insert a new value into the heap
void insert(vector<int>& heap, int value) {
    // 1) Append the new element at the end (as a new leaf)
    heap.push_back(value);
    // 2) Restore heap by bubbling it up from the last index
    heapifyUp(heap, heap.size() - 1);
}

// Delete the minimum element (root) from the heap
void deleteMin(vector<int>& heap) {
    if (heap.empty()) return;  // nothing to delete

    // 1) Move the last leaf to the root position
    heap[0] = heap.back();
    // 2) Remove the last element (we've copied it to root)
    heap.pop_back();
    // 3) Restore heap by bubbling it down from the root
    heapifyDown(heap, 0);
}

// Utility to print the heap array
void printHeap(const vector<int>& heap) {
    for (int v : heap) 
        cout << v << " ";
    cout << endl;
}

int main() {
    vector<int> heap;

    // Insert elements one by one
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 6);
    insert(heap, 7);

    cout << "Initial heap: ";
    printHeap(heap);

    // Remove the minimum (root) twice
    cout << "Delete min: ";
    deleteMin(heap);
    printHeap(heap);

    cout << "Delete min: ";
    deleteMin(heap);
    printHeap(heap);

    return 0;
}
