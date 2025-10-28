#include <iostream>
#include <vector>
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

// ===== Main Function =====
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter a number to search: ";
    cin >> target;

    cout << "Binary Search result: ";
    performSearch(arr, size, target, binarySearch);

    cout << "iterative Sequential Search result: ";
    performSearch(arr, size, target, sequentialSearch);
}
