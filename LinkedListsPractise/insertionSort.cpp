#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]= {1,6,78,9,1,2,15,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    int j;
    int temp;
    for (int i = 0; i < n; i++)
    {
        j = i;
        while (j>0 && arr[j]<arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\n";
    }
    
}