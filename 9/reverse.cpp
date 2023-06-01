//Elijah Morris
//3-19-20
//Print a character string in reverse
#include <iostream>
#include <cstring>
using namespace std;
void reverse_string(char phrase[200]);

int main(){
    char phrase[200];
    cout << "Enter a word or phrase: ";
    cin.getline(phrase, 200);
    reverse_string(phrase);
    cout << endl;
    return 0;
}
void reverse_string(char phrase[200]){
    if(strlen(phrase) == 1){
        cout << phrase[0];
        return;
    }
    char c = phrase[0];
    reverse_string(phrase + 1);
    cout << c;
}

