#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150};
    int mid=(sizeof(arr)/sizeof(arr[0]))/2;
    int low=0;
    int target = 110;
    int high=sizeof(arr)/sizeof(arr[0])-1;
    while (low<=high && arr[mid]!=target)
    {
        if (arr[mid]<target)
        {
            low=mid+1;
            mid = (low+high)/2;
        }
        else if(arr[mid]==target){
            break;
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }   
    }
    cout<<"value found at index "<<mid;
    
    return 0;
}