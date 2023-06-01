//Elijah Morris
//2-7-20

#include <iostream>
#include <cstring>
#include "mystring.h"
#include "mystring.h"
using namespace std;
Mystring::Mystring(const char *str){
    strcpy(name, str);
}
int main(){
    Mystring ship_name = "cruise ship";
    return 0;
}
