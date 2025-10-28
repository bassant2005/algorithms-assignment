#include <iostream>
using namespace std;

// ===== Helper Function =====
void performSearch(int arr[], int size, int target,
                   int (*searchFunc)(int[], int, int)) {

    int result = searchFunc(arr, size, target);

    if (result != -1)
        cout << "Element " << target << " found at index " << result << "\n\n";
    else
        cout << "Element " << target << " not found.\n\n";
}

// ===== Binary Search Function =====
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// ===== iterative Sequential Search Function =====
int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Target found, return its index
        }
    }
    return -1;  // Target not found
}

// ===== Recursive function for sequential search =====
int recursiveSequentialSearch(int arr[], int size, int index, int target) {
    cout << "Checking index " << index << "..." << endl;

    if (index == size) {
        cout << "Reached end of array. Target not found.\n";
        return -1;
    }

    if (arr[index] == target) {
        cout << "Found target " << target << " at index " << index << "!\n";
        return index;
    }

    cout << "Value " << arr[index] << " != " << target
         << " → moving to index " << index + 1 << endl;

    return recursiveSequentialSearch(arr, size, index + 1, target);
}

// ===== Wrapper for performSearch compatibility =====
int sequentialSearchWrapper(int arr[], int size, int target) {
    return recursiveSequentialSearch(arr, size, 0, target);
}

// ===== Main Function =====
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "array : ";
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;

    cout << "Enter a number to search: ";
    cin >> target;
    cout << "-------------------------------------------\n";

    cout << "Binary Search result: ";
    performSearch(arr, size, target, binarySearch);
    cout << "-------------------------------------------\n";

    cout << "Recursive Sequential Search: ";
    performSearch(arr, size, target, sequentialSearchWrapper);
    cout << "-------------------------------------------\n";

    cout << "Iterative Sequential Search result: ";
    performSearch(arr, size, target, sequentialSearch);
    cout << "-------------------------------------------\n";
}
