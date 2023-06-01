//Elijah Morris
//3-18-20

#include <iostream>
using namespace std;
void countdown(int n);

int main(){
    int n;
    cout << "Countdown from what number?: ";
    cin >> n;
    countdown(n);
    cout << endl;
    return 0;
}
void countdown(int n){
    if(n == 0)
        return;
    cout << n << " ";
    countdown(n - 1);
}

