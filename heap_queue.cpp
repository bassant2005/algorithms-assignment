#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to maintain heap property (bottom-up)
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Helper function to maintain heap property (top-down)
    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert an element
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        cout << val << " inserted into the heap.\n";
    }

    // Get maximum element
    int getMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[0];
    }

    // Extract (remove) maximum element
    int extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        cout << maxVal << " extracted from the heap.\n";
        return maxVal;
    }

    // Extract (remove) minimum element
    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return -1;
        }

        // The minimum is guaranteed to be in the leaves
        int minIndex = heap.size() / 2;
        for (int i = heap.size() / 2 + 1; i < heap.size(); i++) {
            if (heap[i] < heap[minIndex])
                minIndex = i;
        }

        int minVal = heap[minIndex];
        cout << "Extracted min: " << minVal << endl;

        // Remove it
        heap[minIndex] = heap.back(); // replace with last element
        heap.pop_back();

        // The removed node might violate heap property, so re-heapify
        if (minIndex < heap.size()) {
            heapifyUp(minIndex);
            heapifyDown(minIndex);
        }

        return minVal;
    }

    // Display heap elements
    void display() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }
        cout << "Current heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << "\n";
    }

    // Check if heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

// -------------------- MENU PROGRAM --------------------
int main() {
    MaxHeap h;
    int choice, val;

    do {
        cout << "\n=== MAX HEAP MENU ===\n";
        cout << "1. Insert element\n";
        cout << "2. Get maximum\n";
        cout << "3. Extract maximum\n";
        cout << "4. Extract minimum\n";
        cout << "5. Display heap\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            h.insert(val);
            break;
        case 2:
            if (!h.isEmpty())
                cout << "Maximum element: " << h.getMax() << "\n";
            else
                cout << "Heap is empty!\n";
            break;
        case 3:
            h.extractMax();
            break;
        case 4:
            h.extractMin();
            break;
        case 5:
            h.display();
            break;
        case 6:
            cout << "Exiting program... Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
