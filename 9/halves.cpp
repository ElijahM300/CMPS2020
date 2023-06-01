//Elijah Morris
//Lab 9 Halves Program

#include <iostream> 
using namespace std;
void halves(char *arr, int s, int e);

int main(){
    char arr[100];
    int n = 1;
    cout << "Lab 9 Divide a Word in Half Recursively\n";
    cout << "----------------------------------------\n";
    cout << "Enter a word: ";
    cin.getline(arr, 100);
    for(int i = 0; i < n; i++){
        if(arr[i] != '\0')
            n++;
    }
    halves(arr, 0, n - 1);
    cout << endl;
    return 0;
}

void halves(char *arr, int s, int e){
    if(s == e){
        cout << arr[s] << " ";
        return;
    }
    int mid = (s + e)/2;
    cout << '\"';
    for(int i = s; i < e; i++){
        cout << arr[i];
        if(arr[i] == arr[mid]){
            cout << '\"';
            cout << "-" << '\"';
        }
    }
    cout << arr[e] << '\"';
    cout << "\n";
    halves(arr, s, mid);
    halves(arr, mid + 1, e);
}
