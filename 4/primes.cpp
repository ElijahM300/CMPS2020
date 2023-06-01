//Elijah Morris

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Prime numbers...\n";
    for(int i = 2; i < 10000; i++){
        bool prime = true;
        for(int j = 2; j < sqrt((double)i) + 1; j++){
            if((i % j) == 0)
                prime = false;
        }
        if(prime)
            cout << i << " " << flush;
    }
    cout << endl;
    return 0;
}
