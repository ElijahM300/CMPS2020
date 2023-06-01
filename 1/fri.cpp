//Elijah Morris
//1-31-20

#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

int main(){
    double angle = 0.0;
    while(true){
        double s = sin(angle);
        double c = cos(angle);
        s += 1.0;
        s*= 35.0;
        c += 1.0;
        c *= 35.0;
        for(int i = 0; i < s; i++){
            cout << " ";
        }
        cout << "#\n";
        cout << "..\n";
        usleep(20000);
        angle += 0.1;
    }
    return 0;
}
