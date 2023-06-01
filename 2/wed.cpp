//Elijah Morris
//1-29-20

#include <iostream> 
#include <cstring>
using namespace std;

class Student{
    char *name;
public:
    Student(){
        name = new char[100];
        strcpy(name, "student name");
    }
    Student(const Student &obj){
        name = new char[100];
        strcpy(name, obj.name);
    }
    char *getName(){
        return name;
    }
    void setName(const char *str){
        strcpy(name, str);
    }
};

int main(){
    Student s1;
    Student s2 = s1;
    s1.setName("new name for student");
    cout << s1.getName() << endl;
    cout << s2.getName() << endl;    

    return 0;
}
