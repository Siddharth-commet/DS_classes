//write a program to find sum of every row and every column in a two-dimensional array.

#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    cout << "Row sums:\n";
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
            rowSum += arr[i][j];
        cout << "Row " << i << ": " << rowSum << endl;
    }

    cout << "Column sums:\n";
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++)
            colSum += arr[i][j];
        cout << "Column " << j << ": " << colSum << endl;
    }

    return 0;
}
