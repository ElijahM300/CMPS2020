//Elijah Morris
//3-19-20
//Print a character string in reverse
#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(char phrase[200], int start, int end);

int main(){
    char phrase[200];
    cout << "Enter a possible palindrome: ";
    cin.getline(phrase, 200);
    bool ret = isPalindrome(phrase, 0, strlen(phrase) - 1);
    if(ret == true)
        cout << "It is." << endl;
    else
        cout << "It isn't." << endl;
    cout << endl;
    return 0;
}
bool isPalindrome(char phrase[200], int start, int end){
    if(start >= end)
        return true;
    if(phrase[start] == phrase[end]){
        //possible palindrome
        return isPalindrome(phrase, start + 1, end - 1);
    }
    else
        return false;
}

