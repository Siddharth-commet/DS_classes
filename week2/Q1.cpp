#include <iostream>
#include <vector>
using namespace std;

// Binary Search function
int binarySearch(const vector<int> &arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1; 
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int target;

    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
        {cout << "Element found at index " <<result;}

    return 0;
    
    }
