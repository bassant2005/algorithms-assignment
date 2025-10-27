#include <iostream>
using namespace std;

// Recursive function for sequential search
int recursiveSequentialSearch(int arr[], int size, int index, int target) {
    cout << "Checking index " << index << "..." << endl;

    // Base case: reached end of array
    if (index == size) {
        cout << "Reached end of array. Target not found.\n";
        return -1;
    }

    // If current element matches target
    if (arr[index] == target) {
        cout << "Found target " << target << " at index " << index << "!\n";
        return index;
    }

    // Recursive step: move to the next index
    cout << "Value " << arr[index] << " != " << target
         << " → moving to index " << index + 1 << endl;

    return recursiveSequentialSearch(arr, size, index + 1, target);
}

int main() {
    int arr[] = {3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    cout << "\n--- Starting Recursive Sequential Search ---\n";
    int result = recursiveSequentialSearch(arr, size, 0, target);
    cout << "-------------------------------------------\n";

    if (result != -1)
        cout << "Result: Element found at index " << result << endl;
    else
        cout << "Result: Element not found" << endl;

    return 0;
}
