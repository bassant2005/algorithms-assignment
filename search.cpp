#include <iostream>
using namespace std;

// ===== Binary Search Function =====
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int step = 1;

    cout << "\n===== Binary Search Visualization =====\n";

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Show current state
        cout << "\nStep " << step++ << ": ";
        cout << "Left = " << left << ", Right = " << right
             << ", Mid = " << mid << "\n";

        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            if (i == mid)
                cout << "[" << arr[i] << "] "; // highlight mid
            else
                cout << arr[i] << " ";
        }
        cout << "\n";

        if (arr[mid] == target) {
            cout << "Found target " << target << " at index " << mid << "!\n";
            return mid;
        }
        else if (arr[mid] < target) {
            cout << "Target is greater than " << arr[mid] << ", moving RIGHT\n";
            left = mid + 1;
        }
        else {
            cout << "Target is smaller than " << arr[mid] << ", moving LEFT\n";
            right = mid - 1;
        }
    }

    cout << "Target not found.\n";
    return -1;
}

// ===== Iterative Sequential Search Function =====
int sequentialSearch(int arr[], int size, int target) {
    cout << "\n===== Sequential Search Visualization =====\n";

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << " --> Found target " << target << " at index " << i << "!\n";
            return i;
        }
    }

    cout << "Target not found.\n";
    return -1;
}

// ===== Recursive Sequential Search Function =====
int recursiveSequentialSearch(int arr[], int size, int index, int target) {
    if (index == size) {
        cout << "Reached end of array. Target not found.\n";
        return -1;
    }

    cout << "Checking index " << index << ": value = " << arr[index] << endl;

    if (arr[index] == target) {
        cout << "Found target " << target << " at index " << index << "!\n";
        return index;
    }

    cout << "Value " << arr[index] << " != " << target
         << " --> Moving to index " << index + 1 << "\n";

    return recursiveSequentialSearch(arr, size, index + 1, target);
}

// ===== Wrapper for Recursive Sequential Search =====
int sequentialSearchWrapper(int arr[], int size, int target) {
    cout << "\n===== Recursive Sequential Search Visualization =====\n";
    int result = recursiveSequentialSearch(arr, size, 0, target);
    if (result == -1)
        cout << "Target not found.\n";
    return result;
}

// ===== Main Function =====
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nEnter a number to search: ";
    cin >> target;

    cout << "\n-------------------------------------------\n";
    binarySearch(arr, size, target);

    cout << "-------------------------------------------\n";
    sequentialSearch(arr, size, target);

    cout << "-------------------------------------------\n";
    sequentialSearchWrapper(arr, size, target);

    cout << "-------------------------------------------\n";
}
