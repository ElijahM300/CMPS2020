//Elijah Morris
//3-19-20
//Recursive Multiplication
#include <iostream>
using namespace std;
int multiply(int x, int y);

int main(){
    int x, y;
    cout << "Give 2 numbers to multiply: ";
    cin >> x >> y;
    cout << "The product of your numbers: " << multiply(x, y) << endl;
    cout << endl;
    return 0;
}
int multiply(int x, int y){
    //there are two base cases
    if(y == 0)
        return 0;
    else if(y == 1)
        return x;
    return x + multiply(x, y - 1);
}

