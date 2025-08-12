#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] - arr[0] == mid) {
            // Missing number is in the right half
            low = mid + 1;
        } else {
            // Missing number is in the left half
            high = mid - 1;
        }
    }
    return arr[0] + low;
}

int main() {
    int arr[] = {2, 3, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingBinary(arr, n);
    cout << "Missing Number (Binary Search): " << missing << endl;

    return 0;
}
