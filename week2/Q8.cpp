#include <bits/stdc++.h>
using namespace std;

int countDistinct(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    return s.size();
}

int main() {
    vector<int> arr = {10, 20, 10, 30, 20, 40, 50, 30};
    int n = arr.size();

    cout << "Total distinct elements = " << countDistinct(arr) << endl;
    return 0;
}
