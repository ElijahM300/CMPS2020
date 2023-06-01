//Elijah Morris
//2-6-20
//Modified Boat Program

#include <iostream>
#include <string>
using namespace std;
class Ship{
protected:
    string name;
    string year;
public:
    Ship(string n, string y){
        name = n;
        year = y;
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
    CruiseShip(string n, string y, int p) : Ship(n, y){
        pass = p;
    }
    void print(){
        cout << "Name of ship: " << name << endl;
        cout << "Year ship was built: " << year << endl;
        cout << "Maximum number of passangers: " << pass << endl;
        cout << "\n";
    }
};
class CargoShip : public Ship{
private:
    int capacity;
public:
    CargoShip(string n, string y, int c) : Ship(n, y){
        capacity = c;
    }
    void print(){
        cout << "Name of ship: " << name << endl;
        cout << "Year ship was built: " << year << endl;
        cout << "Cargo capacity in tonnage: " << capacity << endl;
        cout << "\n";
    }
};
/*
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
*/
int main(){
    Ship *s[3] = {
        new Ship("MyYacht", "2018"),
        new CruiseShip("LoveBoat", "1981", 2000),
        new CargoShip("DeBarge", "1974", 45000000)
    };
    cout << endl;
    for(int i = 0; i < 3; i++){
        s[i]->print();
        delete s[i];
    }
    return 0;
}





