//Elijah Morris
//Number Program
//2-4-20

#include <iostream>
using namespace std;

class Number {
        int value;
    public:
        Number(int a) {
            value = a;
        }
        //add overloaded operators here...
        Number operator ++ (){
            ++value;
            return *this;
        }
        Number operator ++ (int){
            Number tmp(value);
            value++;
            return tmp;

        }
        Number operator --(){
            --value;
            return *this;
        }
        Number operator -- (int){
            Number tmp(value);
            value--;
            return tmp;
        }
        friend ostream& operator<<(ostream& os, const Number &n) {
            os << n.value;
            return os;
        }
};
                
int main(void){             
    Number num = 1;
    ++num;
    num--;
    cout << num << " ";
    cout << ++num << " ";
    cout << num++ << " ";
    cout << num-- << " ";
    cout << --num << " ";
    cout << num;
    cout << endl;
    return 0;
}
