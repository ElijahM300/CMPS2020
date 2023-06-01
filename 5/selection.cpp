//Elijah Morris

#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 1000;

int main(){
    int arr[SIZE];
    srand(time(NULL));
    int n = 0;
    int value;
    int index;
    for(int i = 0; i < SIZE; i++){
        arr[n++] = rand()%99 + 1;
    }
    for(int i = 0; i < n - 1; i++){
        value = arr[i];
        index = i;
        for(int j = i + 1; j < n; j++){
            if(value > arr[j]){
                value = arr[j];
                index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }
    for(int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
};
