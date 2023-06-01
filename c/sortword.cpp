//Elijah Morris
//Lab 12 Sortword Program 
//4-9-20
#include <iostream>
#include <cstring>
using namespace std;
void sortword(char *arr, int s, int e);
void sort(char *arr, int s, int m, int e);

int main(){
    char arr[100];
    int n = 1;
    cout << "Lab 12 Sort the Letters of a Word\n";
    cout << "----------------------------------\n";
    cout << "Enter a word: ";
    cin.getline(arr, 100);
    for(int i = 0; i < n; i++){
        if(arr[i] != '\0')
            n++;
    }
    cout << "\n";
    sortword(arr, 0, n - 1);
    cout << "Sorted word: ";
    for(int i = 0; i < n; i++)
        cout << arr[i];
    cout << "\n\n";
    cout << "End of program.\n\n";
    return 0;
}

void sortword(char *arr, int s, int e){
    if(s < e){
        int mid = (s + e)/2;
        sortword(arr, s, mid);
        sortword(arr, mid + 1, e);
        sort(arr, s, mid, e);
    }
}
void sort(char *arr, int s, int m, int e){
    int a = 0;
    int b = 0;
    int c = s;
    int e1 = m - s + 1;
    int e2 = e - m;
    char sort1[100];
    char sort2[100];
    for(int i = 0; i < e1; i++)
        sort1[i] = arr[s + i];
    for(int j = 0; j < e2; j++)
        sort2[j] = arr[m + 1 + j];
    while(a < e1 && b < e2){
        if(sort1[a] <= sort2[b]) {
            arr[c++] = sort1[a];
            a++;
        }
        else{
            arr[c++] = sort2[b];
            b++;
        }
    }
    while(a < e1){
        arr[c++] = sort1[a];
        a++;
    }
    while(b < e2){
        arr[c++] = sort2[b];
        b++;
    }
}

