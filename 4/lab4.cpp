//Elijah Morris
//2-13-20
//Lab 4 Program

#include <iostream>
#include <new>
#include <cstring>
using namespace std;
int searchArray(int arr[], int, int);
char *allocMemory(long long int);
template <class T>
T *memAlloc(T memory);
template <class T>
void showArr(T arr2[], T size);
template <class T1, class T2>
void showValues(T1 x, T2 y);
template <class T>
void arrange(T &var1, T &var2, T &var3);
template <class T>
void sumOfSquares(T arr[], int size);

int main(){
    char input;
    int number;
    int arr[5] = {2, 8, 4, 1, 6};
    int index;
    char *str = nullptr;
    long long int amount;
    int memory;
    int *arrPtr = nullptr;
    int arr2[5] = {1, 9, 3, 4, 7};
    float f;
    char a;
    const char *s = "hello";
    long double l; 
    int var1, var2, var3;
    double x, y, z;
    char c, d, e;
    int arr3[5] = {4, 1, 2, 5, 9};
    double arr4[5] = {1.6, 2.3, 5.2, 3.7, 6.1};

    do{
        cout << "Lab-4 Menu of options\n";
        cout << "----------------------\n";
        cout << " 1. Search an array\n"; 
        cout << " 2. Allocate memory\n";
        cout << " 3. Allocate memory template\n";
        cout << " 4. Display an array\n";
        cout << " 5. Multiple Parameter Templates\n";
        cout << " 6. Arrange Template\n";
        cout << " 7. Sum of Squares of an Array\n";
        cout << " q. Quit the program\n";
        cout << "----------------------\n";
        cout << "Select menu option: ";
        cin >> input;
        cout << "\n";  
        switch(input){
            case '1':
                cout << "Numbers in array: ";
                for(int i = 0; i < 5; i++){
                    cout << arr[i] << " ";
                }
                cout << "\n";
                cout << "Enter a number to search for: ";
                cin >> number;
                try{
                    index = searchArray(arr, 5, number);
                    cout << "Your number was found at index " << index << endl;
                }
                catch(const char *err){
                    cout << err << endl;
                }
                cout << "\n";
                break;
            case '2':
                cout << "Enter the amount of memory you would like to allocate: ";
                cin >> amount;
                if(allocMemory(amount) == nullptr)
                    break;
                str = allocMemory(amount);
                cout << "Enter a string to store: ";
                cin.ignore();
                cin.getline(str, amount);
                cout << "Your string: " << str;
                cout << "\n\n";
                delete [] str;
                break;
            case '3':
                cout << "Amount of memory to be allocated: ";
                cin >> memory;
                arrPtr = memAlloc(memory);
                cout << "Contents of array: ";
                for(int i = 0; i < memory; i++){
                    arrPtr[i] = i + 1;
                    cout << arrPtr[i] << " ";
                } 
                cout << "\n\n";
                delete [] arrPtr;
                break;            
            case '4':
                cout << "Template program to display array of any type\n\n";
                cout << "Displaying contents of the array: ";
                showArr(arr2, 5);
                cout << "\n";
                break;
            case '5':
                number = 5;
                f = 2.5;
                a = 'g';
                l = 3.14159;
                cout << "Multiple Parameter Templates Program\n\n";
                cout << "Integer and float data types...\n";
                showValues(number, f);
                cout << "Character and character pointer data types...\n";
                showValues(a, s);
                cout << "Integer and long double data types...\n";
                showValues(number, l);
                break;
            case '6':
                var1 = 3;
                var2 = 1;
                var3 = 5;
                cout << "Arrange Program\n\n";
                cout << "Integers in ascending order...\n";
                arrange(var1, var2, var3);
                x = 3.3;
                y = 1.6;
                z = 7.4;
                cout << "Doubles in ascending order...\n";
                arrange(x, y, z);
                c = 'a';
                d = 'z';
                e = 'm';
                cout << "Characters in ascending order...\n";
                arrange(c, d, e);
                cout << "\n";
                break;
            case '7':
                cout << "Sum of Squares of an Array Program\n\n";
                cout << "Integer array sum of squares...\n";
                sumOfSquares(arr3, 5);
                cout << "Double array sum of squares...\n";
                sumOfSquares(arr4, 5);
                break;

        } 

    }while(input != 'q'); 
    return 0;
}
int searchArray(int arr[], int size, int number){
    for(int i = 0; i < size; i++){
        if(arr[i] == number)
            return i;
    }
    throw "Your number was not found";
}
char *allocMemory(long long int amount){
    try{
        char *ptr = new char[amount];
        return ptr;
    }
    catch(bad_alloc){
        cout << "Memory could not be allocated\n\n";
    }
    return nullptr;
}

template <class T>
T *memAlloc(T memory){
    try{
        T *ptr;
        ptr = new T[memory];
        return ptr;
    }
    catch(bad_alloc){
        cout << "Memory could not be allocated\n";
    }
    return nullptr;
}
template <class T>
void showArr(T arr2[], T size){
    for(int i = 0; i < size; i++)
        cout << arr2[i] << " ";
    cout << "\n";
} 
template <class T1, class T2>
void showValues(T1 x, T2 y){
    cout << "Value and size of 1st variable: " << x << ", it is " << sizeof(x) << " bytes\n";
    cout << "Value and size of 2nd variable: " << y << ", it is " << sizeof(y) << " bytes\n";
    cout << "\n";
}
template <class T>
void arrange(T &var1, T &var2, T &var3){
    if(var1 > var2){
        int tmp = var1;
        var1 = var2;
        var2 = tmp;
    }
    else if(var1 > var3){
        int tmp = var1;
        var1 = var3;
        var3 = tmp;
    }
    else{
        int tmp = var2;
        var2 = var3;
        var3 = tmp;
    }
    cout << var1 << ", " << var2 << ", " << var3 << endl; 
}
template <class T>
void sumOfSquares(T arr[], int size){
    T total;
    cout << "Values in array: ";
    for(int i = 0; i < size; i++){
       cout << arr[i];
       if(i < size - 1)
           cout << ", ";
       total = total + (arr[i] * arr[i]);
    }
    cout << "\n";
    cout << "Total of squares in the array: " << total << endl;
    cout << "\n";
}
  




