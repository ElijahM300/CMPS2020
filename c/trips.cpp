//Elijah Morris
//Lab 12 Triples Program 
//4-9-20
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int triples(int *arr, int start, int end);

int main(){
    srand(time(NULL));
    int *arr;
    int s;
    int count = 0;
    cout << "Lab 12 Find Triples of Numbers in an Array\n";
    cout << "-----------------------------\n";
    cout << "Array size?: ";
    cin >> s;
    arr = new int[s];
    cout << "\n";
    cout << "Searching for triples now...";
    for(int i = 0; i < s; i++){
        arr[i] = rand()%9;
    }
    cout << "\n\n";
    while(triples(arr, 0, s - 1) == 0){
        count++;
        for(int i = 0; i < s; i++)
            arr[i] = rand()%9;
    }
    cout << "Found an array with " << triples(arr, 0, s - 1) << " triple(s)!\n\n";
    cout << "Array is: ";
    for(int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
    cout << "That took " << count << " tries.\n";
    delete [] arr;
    cout << endl;
    return 0;
}
int triples(int *arr, int start, int end){
    if(start + 1 == end){
        return 0;
    }
    if(arr[start] == arr[start + 1] && arr[start + 1] == arr[start + 2])
        return 1 + triples(arr, start + 1, end);
    else
        return 0 + triples(arr, start + 1, end);
}

