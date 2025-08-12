//2) Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent
//elements if they are in wrong order. Code the Bubble sort with the following elements:

#include<bits/stdc++.h>
using namespace std;
int main(){
    int temp;
    vector<int> arr = {64,34,25,12,22,11,90};
    for (auto it = arr.end()-1; it != arr.begin(); it--)
    {
        for (auto it2 = arr.begin(); it2 != it; it2++)
        {
            if(*(it2)>*(it2+1)){
                swap(*it2,*(it2+1));
            }
        }
    }

    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout<<*it<<"\n";
    }
    return 0;
}