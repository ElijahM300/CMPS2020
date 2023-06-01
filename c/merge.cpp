//Elijah Morris
//Merge Sort Program 
//4-8-20

#include <iostream>
using namespace std;

int main(){
    //           half          half
    int arr[] = {1, 5, 6,      2, 3, 8};
    //           a     e1      b     e2
    int n = 6;
    //turn the merge below into a function
    //prototype: merge(int *arr, int s, int m, int e, int *merged);
    //call like this: merge(arr, 0, 2, 5, merged); 
    int merged[6]{0, 0, 0, 0, 0, 0};
    int a  = 0;
    int b = 3;
    int e1 = 2;
    int e2 = 5;
    int c = 0; 
    while(a <= e1 && b <= e2){
        if(arr[a] <= arr[b]){
            merged[c++] = arr[a];
            ++a;
        }
        else{
            merged[c++] = arr[b];
            ++b;
        }
    }
    while(a <= e1){
        merged[c++] = arr[a];
        ++a;
    }
    while(b <= e2){
        merged[c++] = arr[b];
        ++b;
    }
    for(int i = 0; i < n; i++)
        cout << merged[i] << " ";
    cout << "\n";
    return 0;
