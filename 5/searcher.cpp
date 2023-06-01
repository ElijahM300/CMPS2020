//Elijah Morris
//Searcher Program

#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int number);
int binarySearch(int arr[], int size, int number);
void bubbleSort(int arr[], int size);

int main(){
    srand(time(NULL));
    int arr[20];
    int number;
    for(int i = 0; i < 20; i++)
        arr[i] = rand()%99 + 1;
    cout << "Search Benchmarks\n";
    cout << "----------------\n";
    cout << "Elements in the array: ";
    for(int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "Enter a value to search for: ";
    cin >> number;
    cout << "\n";
    cout << "Now searching for the value using a linear search...\n";
    if(linearSearch(arr, 20, number) == -1)
        cout << "The value was not found\n";
    else 
        cout << "The value was found in " << linearSearch(arr, 20, number) << " comparisons" << endl;
    cout << "\n";
    cout << "Now ordering array for a binary search...\n";
    bubbleSort(arr, 20);
    cout << "Ordered Array: ";
    for(int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
    cout << "Now searching for the value using a binary search...\n";
    if(binarySearch(arr, 20, number) == -1)
        cout << "The value was not found\n";
    else 
        cout << "The value was found in " << binarySearch(arr, 20, number) << " comparisons" << endl;
    cout << "\n";
    return 0;
}
int linearSearch(int arr[], int size, int number){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == number){
            count++;
            return count;
        }
        else 
            count ++;
    }
    return -1;
}
int binarySearch(int arr[], int size, int number){
    int start = 0;
    int end = size - 1;
    int mid;
    int count = 0;
    do{
        mid  = (start + end)/2;
        if(arr[mid] == number){
            count++;
            return count;
        }
        else if(arr[mid] < number)
            start = mid + 1;
        else 
            end = mid - 1;
        count++;
    }while(start <= end);
    return -1;
}
void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}




