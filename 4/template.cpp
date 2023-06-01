//Elijah Morris

#include <iostream>
#include <iomanip>
using namespace std;
#define CUBE(a) (a*a*a)
template <class T>
T cube(T a);

int main(){
    int a;
    float f;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Your number cubed is: " << CUBE(a) << endl;
    cout << "Enter a real number: ";
    cin >> f;
    cout << "Your real number cubed is: " << setprecision(5) << fixed << cube(f) << endl;
    return 0;
}
template <class T>
T cube(T a){
    T answer = a*a*a;
    return answer;
}
