#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int lower[size];

    cout << "Enter lower triangular elements row-wise: ";
    for (int i = 0; i < size; i++) cin >> lower[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << lower[i*(i+1)/2 + j] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
}
