//Elijah Morris

#include <iostream>
#include <unistd.h>
using namespace std;
const int SIZE = 1000;

int main(){
    int n = 0;
    int arr[SIZE];
    srand(time(NULL));
    cout << "How many values to sort?: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        arr[i] = rand()%60 + 1;
    //insertion sort
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
    cout << "\n";
    return 0;
}
