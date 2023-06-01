//Elijah Morris

#include <iostream>
using namespace std;

class Base{
    public:
        Base(){
            cout << "Base constructor\n";
        }
       // virtual void showName(){
       //     cout << "base name\n";
       // }
       virtual void showName() = 0;
       
};
class Derived : public Base{
    public: 
        Derived(){
            cout << "Derived constructor\n";
        }
        void showName(){
            cout << "derived name\n";
        }
};

int main(){
   //Base b;
    Derived d;
    Base *x = &d;
    x->showName();
    return 0;
}
