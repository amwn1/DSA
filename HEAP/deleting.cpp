#include <iostream>
#include <vector>
using namespace std;

// Helper to swap downwards
void heapifyDown(vector<int>& heap, int index) {
    int size = heap.size();
    while (index < size) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Find smallest among index and children
        if (leftChild < size && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        if (rightChild < size && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // If index is smallest → done
        if (smallest == index)
            break;

        swap(heap[index], heap[smallest]);
        index = smallest;  // move down
    }
}

// Heapify upwards (already done before)
void heapifyUp(vector<int>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Insert into heap
void insert(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

// Delete root element (min in min-heap)
void deleteMin(vector<int>& heap) {
    if (heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(heap, 0);
}

// Print heap array
void printHeap(const vector<int>& heap) {
    for (int v : heap) cout << v << " ";
    cout << endl;
}

int main() {
    vector<int> heap;
    insert(heap, 5);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);
    insert(heap, 6);
    insert(heap, 7);

    cout << "Initial heap: ";
    printHeap(heap);

    cout << "Delete min: ";
    deleteMin(heap);
    printHeap(heap);

    cout << "Delete min: ";
    deleteMin(heap);
    printHeap(heap);

    return 0;
}
