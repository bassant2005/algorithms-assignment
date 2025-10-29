#include <iostream>
using namespace std;

// ===== Iterative Binary Search Function =====
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
    int step = 1;

    for (int i = 0; i < size; i++) {
        cout << "\nStep " << step++ << ": Checking index " << i << endl;
        cout << "Array: ";
        for (int j = 0; j < size; j++) {
            if (j == i)
                cout << "[" << arr[j] << "] "; // highlight current element
            else
                cout << arr[j] << " ";
        }
        cout << "\n";

        if (arr[i] == target) {
            cout << " Found target " << target << " at index " << i << "!\n";
            return i;
        } else {
            cout << " " << arr[i] << " != " << target << " --> Moving to next element\n";
        }
    }

    cout << "\nReached end of array. Target not found.\n";
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

// ===== Recursive Binary Search Function =====
int recursiveBinarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        cout << "Target not found in this range.\n";
        return -1;
    }

    int mid = low + (high - low) / 2;

    cout << "Checking middle index " << mid << " (value = " << arr[mid] << ")\n";

    if (arr[mid] == target) {
        cout << "Found target " << target << " at index " << mid << "!\n";
        return mid;
    } else if (arr[mid] > target) {
        cout << "Target is smaller than " << arr[mid] << " --> Searching LEFT half\n";
        return recursiveBinarySearch(arr, low, mid - 1, target);
    } else {
        cout << "Target is greater than " << arr[mid] << " --> Searching RIGHT half\n";
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }
}

// ===== Wrapper for Recursive Binary Search =====
int binarySearchWrapper(int arr[], int size, int target) {
    cout << "\n===== Recursive Binary Search Visualization =====\n";
    int result = recursiveBinarySearch(arr, 0, size - 1, target);
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
    binarySearchWrapper(arr, size, target);

    cout << "-------------------------------------------\n";
}
