#include <iostream>
#include <cstring>
using namespace std;
void foo(int arr[], int n);

int main(){
    int arr[] = {2, 4, 6, 8, 9, 10, 12, 13, 15, 16, 21, 28};
    int n = 12; 
    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;    
    foo(arr, n);
    return 0;
}

void foo(int arr[], int n){
    for(int i = 4; i < n; i++)
        arr[i - 1] = arr[i];
    n = n - 1;
    cout << "Modified Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
