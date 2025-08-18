#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> str(10,vector<char>(10));
    int numOfstr;
    cout<<"please enter the number of strings: "<<;
    cin>>numOfstr;

    for (int i = 0; i < numOfstr; i++)
    {
        cout<<"Enter the string"<<i;
        cin.getline(str[i][0],10);
    }
    

    return 0;
}