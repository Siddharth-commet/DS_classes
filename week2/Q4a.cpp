#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[50];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 50);

    int i = 0;
    while (str1[i] != '\0') { // find end of first string
        i++;
    }

    int j = 0;
    while (str2[j] != '\0') { // append second string
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';

    cout << "Concatenated String: " << str1 << endl;
    return 0;
}
