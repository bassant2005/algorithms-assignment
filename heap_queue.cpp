#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//===== MaxHeap =====
class MaxHeap {
private:
    vector<int> heap;

    // Maintain heap property (bottom-up)
    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Maintain heap property (top-down)
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

        int minIndex = heap.size() / 2;
        for (int i = heap.size() / 2 + 1; i < heap.size(); i++) {
            if (heap[i] < heap[minIndex])
                minIndex = i;
        }

        int minVal = heap[minIndex];
        cout << "Extracted min: " << minVal << endl;

        heap[minIndex] = heap.back();
        heap.pop_back();

        if (minIndex < heap.size()) {
            heapifyUp(minIndex);
            heapifyDown(minIndex);
        }

        return minVal;
    }

    // Display heap as a structured binary tree (well-aligned)
    void display() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "\n========== HEAP VISUALIZATION ==========\n\n";

        int n = heap.size();
        int height = log2(n) + 1;
        int index = 0;

        for (int level = 0; index < n; level++) {
            int nodesAtLevel = pow(2, level);
            int count = min(nodesAtLevel, n - index);

            // Adjust spacing (tuned for better pyramid shape)
            int spacesBefore = pow(2, height - level + 1);
            int spacesBetween = pow(2, height - level + 2);

            // Print leading spaces
            cout << string(spacesBefore, ' ');

            // Print node values for this level
            for (int i = 0; i < count; i++) {
                cout << heap[index + i];
                if (i < count - 1)
                    cout << string(spacesBetween, ' ');
            }

            cout << "\n";

            // Print the connecting branches (aligned under nodes)
            if (index + count < n) {
                int branchSpacesBefore = spacesBefore - 1;
                int betweenBranches = spacesBetween - 3;

                cout << string(branchSpacesBefore, ' ');
                for (int i = 0; i < count; i++) {
                    cout << "/  \\";
                    if (i < count - 1)
                        cout << string(betweenBranches, ' ');
                }
                cout << "\n";
            }

            index += count;
        }

        cout << "\n================================================================================\n";
    }

    // Check if heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

// ===== HEAP SORT using the same heapifyDown =====
void heapSort() {
    vector<int> arr;
    int val = 0;
    MaxHeap heap;

    cout << "Enter elements(when you are done enter -1): ";
    while (true){
        cin >> val;
        if(val == -1) break;
        arr.push_back(val);
    }
    cout << endl;

    // Step 1: Insert all elements into the heap
    for (int val : arr) {
        heap.insert(val);
    }
    cout << endl;

    // Step 2: Extract max repeatedly to build a sorted array (ascending)
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = heap.extractMax();  // Extract max each time
    }
    cout << endl;

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    cout << endl;
}

// =====  MENU FUNCTION =====
void runHeapMenu() {
    MaxHeap h;
    int choice, val;

    while (true) {
        cout << "\n=== MAX HEAP MENU ===\n";
        cout << "1. Insert element\n";
        cout << "2. Get maximum\n";
        cout << "3. Extract maximum\n";
        cout << "4. Extract minimum\n";
        cout << "5. Display heap\n";
        cout << "6. Heap Sort\n";
        cout << "7. Exit\n";
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

            case 6: {
                heapSort();
                break;
            }

            case 7:
                cout << "Exiting program... Goodbye!\n";
                return; // ✅ clean exit

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

// ===== MAIN FUNCTION =====
int main() {
    runHeapMenu();
}
