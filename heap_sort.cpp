#include <iostream>
#include <vector>
using namespace std;


void MaxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Assume current node is the largest
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(vector<int>& arr) {
    int size = (int)arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, size, i);

}