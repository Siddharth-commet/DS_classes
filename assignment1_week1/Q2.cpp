//Design the logic to remove the duplicate elements from an Array and after the 
// deletion the array should containtheunique elements.



#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++ ) {
            if (arr[i] == arr[j]) {
                // Shift elements to the left
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; 
            }
        }
    }
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    return 0;
}
