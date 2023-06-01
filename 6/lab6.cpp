//Elijah Morris

#include <iostream>
#include <unistd.h>
using namespace std;
const int SIZE = 1000;
void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);

int main(){
    int n = 0;
    int arr[SIZE];
    char option;
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        arr[i] = rand()%60 + 1;
    do{
        cout << "Sorting Algorithms Animations\n";
        cout << "------------------------------\n";
        cout << " 1. Insertion Sort Animation\n";
        cout << " 2. Bubble Sort Animation\n";
        cout << " q. Quit\n";
        cout << "------------------------------\n";
        cout << "Select animation: ";
        cin >> option;
        cout << "\n";
        switch(option){
            case '1': 
                cout << "How many values to sort?: ";
                cin >> n;
                for(int i = 0; i < n; i++)
                    arr[i] = rand()%60 + 1;
                insertionSort(arr, n);
                cout << "\n";
                break;
            case '2':
                cout << "How many values to sort?: ";
                cin >> n;
                for(int i = 0; i < n; i++)
                    arr[i] = rand()%60 + 1;
                bubbleSort(arr, n);
                cout << "\n";
                break;
        }
    }while(option != 'q');
    return 0;
}
void insertionSort(int arr[], int n){
    int tmp;
    int a;
    for(int i = 1; i <= n; i++){
        tmp = arr[i];
        a = i;
        for(int j = i - 1; j >= 0; j--){
            if(arr[j] > tmp){
                arr[a] = arr[a - 1];
                --a;
            }
        }
        arr[a] = tmp;
        for(int k = 0; k < n; k++){
            for(int m = 0; m < arr[k]; m++)
                cout << "#";
            cout << "\n";
        }
        usleep(400000);
    }
}
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1;j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        } 
        for(int k = 0; k < n; k++){
            for(int m = 0; m < arr[k]; m++)
                cout << "#";
            cout << "\n";
        }
        usleep(400000);
    }
}
