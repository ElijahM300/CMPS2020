//Elijah Morris
//3-20-20
//Recursive Binary Search 
//A reduce and conquer algorithm
#include <iostream>
using namespace std;
int binsearch(int arr[], int start, int end, int value);

int main(){
    int arr[] = {1, 2, 6, 9, 15, 25, 35, 40, 41, 50, 60, 75, 88, 89, 91, 96, 98};
    int n = sizeof(arr)/sizeof(int);
    int value;
    cout << "n: " << n << endl;
    cout << "Search for what number?: ";
    cin >> value;
    int index = binsearch(arr, 0, n - 1, value);
    if(index >= 0)
        cout << "Found!\n";
    else 
        cout << "Not found!\n";
    cout << endl;
    return 0;
}
int binsearch(int arr[], int start, int end, int value){
    if(start > end)
        return -1;
    int mid = (start + end)/2;
    if(arr[mid] == value)
        return mid;
    if(arr[mid] > value){
        end = mid - 1;
        return binsearch(arr, start, end, value);
    }
    else{
        start = mid + 1;
        return binsearch(arr, start, end, value);
    }
}

