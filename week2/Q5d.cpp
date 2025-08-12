#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int size = n*(n+1)/2;
    int upper[size];

    cout << "Enter upper triangular elements row-wise: ";
    for (int i = 0; i < size; i++) cin >> upper[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                int index = i*n - (i*(i-1))/2 + (j - i);
                cout << upper[index] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}
