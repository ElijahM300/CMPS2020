//Elijah Morris
//Quick Sort Program 
//5-4-20
#include <iostream>
#include <ctime>
using namespace std;
//Activate directive to run Intro sort
//Comment-out to run quicksort
#define INTRO_SORT
void quicksort(int *arr, int, int);
int partition(int *arr, int, int);
void bubblesort(int *arr, int, int);

int main(){
    srand(time(NULL));
    //int arr2[] = {1, 5, 6, 4, 3, 8};
    //           0  1  2  3  4  5
    //           i              j
    int *arr = new int[100];
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << endl;
    cout << "Random Array: ";
    for(int i = 0; i < n; i++){
        arr[i] = rand()%50;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    //partition the array 
    int start = 0;
    int end = n - 1;
    quicksort(arr, start, end);
    //reverse the array values
    for(int i = 0; i < n; i++){
        int j = n - 1 - i;
        int tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
    quicksort(arr, start, end);
    cout << "Ordered Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
    delete [] arr;
    return 0;
}

void quicksort(int *arr, int s, int e){
    if(s == e)
        return;
#ifdef INRO_SORT
    if((e - s + 1) < 7){
        bubblesort(arr, s, e);
        return;
    }
#endif
    int p = partition(arr, s, e);
    quicksort(arr, s, p);
    quicksort(arr, p + 1, e);
}

int partition(int *arr, int s, int e){
    //The code below is optimized
    int pivot = arr[(s + e) >> 1];
    int i = s - 1;
    int j = e + 1;
    while(true){
        do{
            i = i + 1;
        } while(arr[i] < pivot);
        do{
            j = j - 1;
        } while(arr[j] > pivot);
        if(i >= j)
            return j;
        //swap
        //optimizing the swap of two integers
        //old cold
        //int tmp = arr[i];
        //arr[i] = arr[j];
        //arr[j] = tmp;
        //new code
        arr[i] ^= arr[j];
        arr[j] ^= arr[i];
        arr[i] ^= arr[j];
    }
}

void bubblesort(int *arr, int s, int e){
    int n = e - s + 1;
    for(int i = 0; i < n - 1; i++){
        for(int j = s; j < e - i; j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}








