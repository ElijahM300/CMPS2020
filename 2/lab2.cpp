//Elijah Morris
//1-30-20
//Lab 2

#include <iostream>
#include <cstring>
using namespace std;
class Mystring{
    char *str;
    int allocated_size;
public:
    Mystring(){
        //cout << "default constructor\n";
        str = NULL;
        allocated_size = 0;
    }
    Mystring(const char *word){
        //cout << "overloaded constructor\n";
        allocated_size = 0;
        char *p = (char *)word;
        while(*p){
            ++allocated_size;
            ++p;
        }
        ++allocated_size;
        str = new char[allocated_size];    
        strcpy(str, word);
    }
    Mystring(const char c){
        allocated_size = 2;
        str = new char[2];    
        str[0] = c;
        str[1] = '\0';
    }
    Mystring(Mystring &obj){
       // cout << "copy constructor\n";
        allocated_size = obj.allocated_size;
        str = new char[allocated_size];
        strcpy(str, obj.str);

    }
    int length(){
        int length;
        length = strlen(str);
        return length;
    }
    void erase(){
        delete [] str;
    }
    friend istream& getline(istream &in, Mystring &ms){
        in >> ms.str;
        return in;
    }
    friend ostream& operator << (ostream& os, const Mystring& ms){
        os << ms.str;
        return os;
    }
    friend istream& operator >> (istream& is, Mystring& ms){
        is >> ms.str;
        return is;
    }
    void operator = (const char *word){
        delete [] str;
        int len = strlen(word);
        allocated_size = len + 1;
        str = new char[allocated_size];
        strcpy(str, word);
    }
    bool operator < (const Mystring& ms){
        bool less;
        if(strcmp(str, ms.str) < 0)
            less = true;
        else 
            less = false;
        return less;
    }
    bool operator > (const Mystring& ms){
        bool great;
        if(strcmp(str, ms.str) > 0)
            great = true;
        else 
            great = false;
        return great;
    }
    bool operator == (const Mystring& ms){
        bool equal;
        if(strcmp(str, ms.str) == 0)
            equal = true;
        else
            equal = false;
        return equal;
    }
    bool operator != (const Mystring& ms){
        bool notEqual;
        if(strcmp(str, ms.str) != 0)
            notEqual = true;
        else 
            notEqual = false;
        return notEqual;
    }
    Mystring operator + (const Mystring &ms){
        int len1 = strlen(str);
        int len2 = strlen(ms.str);
        int len = len1+ len2 + 1;
        char *t = new char[len];
        strcpy(t, str);
        strcat(t, ms.str);
        Mystring tmp(t);
        delete [] t;
        return tmp;
    }
    void operator += (Mystring ms){
        strcat(str, ms.str);      
    }
};

int main(){
    Mystring a; 
    Mystring b("CSU Bakersfield");
    Mystring c('A');
    Mystring copy(b);
    cout << "Displaying the strings...\n\n";
    cout << "The value of b **" << b << "**" << endl;
    cout << "The value of c **" << c << "**" << endl;
    cout << "The value of copy **" << copy << "**" << endl;
    cout << "\n";

    cout << "Enter some new text...\n\n";
    cout << "Enter a string for c: ";
    cin >> c;
    cout << "The value of c **" << c << "**" << endl;
    cout << "\n";

    cout << "Overload operators...\n\n";
    a = b;
    cout << "Assignment: a = b **" << a << "**" << endl;
    cout << "\n";
    cout << "Comparison operators...\n\n";
    cout << "Less than test...\n";
    if(a < b)
        cout << "(a < b) is true\n";
    else 
        cout << "(a < b) is false\n";
    cout << "Greater than test...\n";
    if(a > b)
        cout << "(a > b) is true\n";
    else 
        cout << "(a > b) is false\n";
    cout << "Equality test...\n";
    if (a == b)
        cout << "(a == b) is true\n";
    else
        cout << "(a == b) is false\n";
    cout << "Not equal test...\n";
    if(a != b)
        cout << "(a != b) is true\n";
    else 
        cout << "(a != b) is false\n";
    cout << "\n";

    cout << "Lengths...\n" << endl;
    cout << "Length of each string...\n";
    cout << "length of a: " << a.length() << endl;
    cout << "length of b: " << b.length() << endl;
    cout << "length of c: " << c.length() << endl;
    cout << "length of copy: " << copy.length() << endl;

    cout << "More testing code is below...\n" << endl;
    Mystring add1("add1");
    Mystring add2("add2");
    Mystring add3;
    add3 = add1 + add2;
    cout << "The value of add3 **" << add3 << "**" << endl;

    Mystring add4;
    add4 = add1 + add2;
    cout << "The value of add4 **" << add4 << "**" << endl;

    Mystring add5("-end-");
    add4 += add5;
    cout << "The value of add4 **" << add4 << "**" << endl;

    cout << "Test of getline...\n" << endl;
    cin.ignore();
    Mystring g;
    cout << "Please enter a sentence...\n";
    getline(cin, g);
    cout << "The value of g **" << g << "**" << endl;

    return 0;
}
