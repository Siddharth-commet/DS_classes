#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int size = 3*n - 2;
    int tri[size];

    cout << "Enter tri-diagonal elements: ";
    for (int i = 0; i < size; i++) cin >> tri[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << tri[i] << " ";
            else if (i == j+1)
                cout << tri[n + i - 1] << " ";
            else if (i == j-1)
                cout << tri[2*n - 1 + i] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
    }
}
