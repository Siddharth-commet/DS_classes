#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int sym[size];

    cout << "Enter lower triangular part (row-wise): ";
    for (int i = 0; i < size; i++) cin >> sym[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << sym[i*(i+1)/2 + j] << " ";
            else
                cout << sym[j*(j+1)/2 + i] << " ";
        }
        cout << "\n";
    }
}
