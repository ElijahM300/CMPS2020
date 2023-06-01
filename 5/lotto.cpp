//Elijah Morris
//2-20-20
//Lottery Program

#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int number);
int binarySearch(int arr[], int size, int number);
void bubbleSort(int arr[], int size);

int main(){
    int arr[10] = {13579, 62483, 26791, 77777, 26792, 
                   79422, 33445, 85647, 55555, 93121};
    int number;
    cout << "Lottery Winners Program\n";
    cout << "------------------------\n";
    cout << "Your lottery numbers: ";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "Enter this week's winning 5-digit lottery number: ";
    cin >> number;
    cout << "\n";
    cout << "Searching for your number now using a linear search...\n\n";
    linearSearch(arr, 10, number);
    cout << "Ordering your numbers...\n";
    bubbleSort(arr, 10);
    cout << "Your lottery numbers ordered: ";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";
    cout << "Now searching for your number using a binary search...\n\n";
    binarySearch(arr, 10, number);
    if(linearSearch(arr, 10, number) == -1 && binarySearch(arr, 10, number) == -1)
        cout << "Sorry. You're not a winner this week.\n";
    else{ 
        cout << "Congratulations! You're a lucky winner for this weeks lottery!\n";
        cout << "Your winning number: " << number << endl;
    }
    cout << "\n"; 
    return 0;
}
int linearSearch(int arr[], int size, int number){
    for(int i = 0; i < size; i++){
        if(arr[i] == number)
            return i;
    }
    return -1;
}
int binarySearch(int arr[], int size, int number){
    int start = 0;
    int end = size - 1;
    int mid;
    do{
        mid = (start + end)/2;
        if(arr[mid] == number)
            return mid;
        else if(arr[mid] < number)
            start = mid + 1;
        else 
            end = mid - 1;
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





