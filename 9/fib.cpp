//Elijah Morris
//3-20-20
//Fibonacci numbers

#include <iostream>
using namespace std;
int fibonacci(int n);

int main(){
    int n;
    cout << "Which Fibonacci number to see: ";
    cin >> n;
    cout << fibonacci(n) << endl;
    cout << endl;
    return 0;
}
int fibonacci(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;    
    return fibonacci(n - 1) + fibonacci(n - 2); 
}

