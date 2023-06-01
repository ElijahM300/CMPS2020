//Elijah Morris
//2-6-20
//Boats Program

#include <iostream>
#include <cstring>
using namespace std;
class Ship{
protected:
    string name;
    string year;
public:
    Ship(){
        name = "Washington";
        year = "2000";
    }
    virtual void print(){
        cout << "Name of ship: " << name << endl;
        cout << "Year ship was built: " << year << endl;
        cout << "\n";
    }
    virtual ~Ship(){

    }
};
class CruiseShip : public Ship{
private:
    int pass;
public:
    CruiseShip(){
        pass = 1000;
    }
    void print(){
        cout << "Name of ship: " << name << endl;
        cout << "Maximum number of passangers: " << pass << endl;
        cout << "\n";
    }
};
class CargoShip : public Ship{
private:
    int capacity;
public:
    CargoShip(){
        capacity = 100000;
    }
    void print(){
        cout << "Name of ship: " << name << endl;
        cout << "Cargo capacity in tonnage: " << capacity << endl;
        cout << "\n";
    }
};
int main(){
    Ship *s[3];
    s[0] = new Ship();
    s[1] = new CruiseShip();
    s[2] = new CargoShip();
    for(int i = 0; i < 3; i++){
        s[i]-> print();
        delete s[i];
    }
    return 0;
}







