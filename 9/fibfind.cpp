//Elijah Morris
//3-25-20
//Find fibonacci numbers program

#include <iostream>
using namespace std;
int fibonacci(int num);
int binsearch(int *arr, int start, int end, int value, int count);

int main(){
    int *arr;
    int n = 0;
    int num = 2;
    int value;
    arr = new int[100];
    cout << "Find a Fibonacci number program\n";
    cout << "--------------------------------\n";
    cout << "Filling an array with Fibonacci numbers...\n";
    while(n < 42){
        arr[n] = fibonacci(num);
        num++;
        n++;
    }
    cout << "Done.\n\n";
    cout << "Which Fibonacci number do you want to serach for?: ";
    cin >> value;
    int comp = binsearch(arr, 0, n - 1, value, 0);
    if(comp >= 1)
        cout << "Number was found!\n";
    else
        cout << "Number was not found!\n";
    cout << "Number of comparisons that were needed: " << comp << endl;
    delete [] arr; 
    cout << endl;
    return 0;
}
int fibonacci(int num){
    if(num == 1)
        return 1;
    if(num == 2)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}
int binsearch(int *arr, int start, int end, int value, int count){
    if(start > end)
        return -1;
    int mid = (start + end)/2;
    if(arr[mid] == value){
        count++;
        return count;
    }
    if(arr[mid] > value){
        end = mid - 1;
        count++;
        return binsearch(arr, start, end, value, count);
    }
    else{
        start = mid + 1;
        count++;
        return binsearch(arr, start, end, value, count);
    }
}


