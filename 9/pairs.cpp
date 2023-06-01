//Elijah Morris
//Lab 9 Pairs Program

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int pairs(int *arr, int start, int end);

int main(){
    srand(time(NULL));
    int *arr;
    int s;
    cout << "Lab 9 Find Pairs of Numbers in an Array\n";
    cout << "-----------------------------\n";
    cout << "Array size?: ";
    cin >> s;
    arr = new int[s];
    cout << "Array with random numbers: ";
    for(int i = 0; i < s; i++){
        arr[i] = rand()%9;
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    cout << "This array has " << pairs(arr, 0, s - 1) << " pair(s).\n";
    cout << endl;
    return 0;
}
int pairs(int *arr, int start, int end){
    if(start >= end)
        return 0;
    if(arr[start] == arr[start + 1])
        return 1 + pairs(arr, start + 1, end);
    else
        return 0 + pairs(arr, start + 1, end);
}
