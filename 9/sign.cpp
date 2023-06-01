//Elijah Morris
//3-19-20

#include <iostream>
using namespace std;
void sign(int n);
int sum(int arr[], int n);

int main(){
    int n;
    cout << "Print sign how many times?: ";
    cin >> n;
    sign(n);
    cout << endl;
    //sum of array elements
    int arr[] = {1, 25, 3, 8, 13};
    n = sizeof(arr) / sizeof(int);
    cout << "Sum of all array elements: " << sum(arr, n) << endl;
    cout << endl;
    return 0;
}
void sign(int n){
    if(n == 0)
        return;
    cout << "No parking!\n";
    sign(n - 1);
}
int sum(int arr[], int n){
    if(n == 1)
        return arr[0];
    return arr[0] + sum(arr + 1, n - 1);
}

