#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long invCount = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            invCount += (n1 - i); 
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return invCount;
}

// Recursive merge sort function
long long countInversions(vector<int>& arr, int l, int r) {
    long long invCount = 0;
    if (l < r) {
        int m = (l + r) / 2;
        invCount += countInversions(arr, l, m);
        invCount += countInversions(arr, m + 1, r);
        invCount += mergeAndCount(arr, l, m, r);
    }
    return invCount;
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};  
    int n = arr.size();

    long long result = countInversions(arr, 0, n - 1);
    cout << "Number of inversions = " << result << endl;

    return 0;
}
