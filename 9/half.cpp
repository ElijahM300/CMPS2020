//Elijah Morris

#include <iostream> 
using namespace std;
void half(int *arr, int s, int e);

int main(){
    int arr[] = {1, 2};
    int n = 2;
    half(arr, 0, n - 1);
    cout << endl;
    return 0;
}

void half(int *arr, int s, int e){
    if(s == e){
        cout << arr[s] << endl;
        return;
    }
    int mid = (s + e)/2;
    half(arr, s, mid);
    half(arr, mid + 1, e);
}
