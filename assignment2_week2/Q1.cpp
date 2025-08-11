// 1) Developa Menu driven program to demonstrate the following operations of Arrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT

#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int arrSize = 0;

// Function to create array
void createArray() {
    cout << "Enter number of elements: ";
    cin >> arrSize;
    if (arrSize > MAX) {
        cout << "Size exceeds max limit!" << endl;
        arrSize = 0;
        return;
    }
    cout << "Enter elements: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
}

// Function to display array
void displayArray() {
    if (arrSize == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert element
void insertElement() {
    if (arrSize >= MAX) {
        cout << "Array is full. Cannot insert." << endl;
        return;
    }
    int pos, val;
    cout << "Enter position to insert (0 to " << arrSize << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    if (pos < 0 || pos > arrSize) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = arrSize; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    arrSize++;
    cout << "Element inserted successfully." << endl;
}

// Function to delete element
void deleteElement() {
    if (arrSize == 0) {
        cout << "Array is empty. Cannot delete." << endl;
        return;
    }
    int pos;
    cout << "Enter position to delete (0 to " << arrSize - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= arrSize) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < arrSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arrSize--;
    cout << "Element deleted successfully." << endl;
}

void linearSearch() {
    if (arrSize == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}
int main() {
    int choice;
    while (true) {
        cout << "\n——MENU——\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program."; return 0;
            default: cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
