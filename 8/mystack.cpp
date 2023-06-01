//Elijah Morris
//Homework 8
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const char filename[] = "/usr/share/dict/cracklib-small";

template <class T>
class Stack{
private:
    T value[100];
    int top;
public:
    Stack(){
        top = -1;
    }
    bool isFull(){
        return (top >= 65);  
    }
    bool isEmpty(){
        return (top < 0);
    }
    void push(T c){
        if(isFull()){
            cout << "Stack Overflow!";
            return;
        }
        top++;
        value[top] = c;
    }
    T pop(){
        if(isEmpty()){
            cout << "Stack Underflow!";
            return -1;
        }
        return value[top--]; 
    }

};

int main(){
    Stack<char> s;
    char w[100];
    char word[100];
    char tmp[100];
    char arr[52875][65];
    int n = 0;
    cout << "Homework 8\n";
    cout << "-----------\n";
    cout << "Reverse a dictionary word using a stack\n\n";
    ifstream fin;
    fin.open(filename);
    if(fin.fail()){
        cout << "ERROR! Could not open file " << filename << endl;
        exit(0);
    }
    cout << "Storing dictionary file now...\n";
    while(n < 52875){
        fin >> w;
        strcpy(arr[n], w);
        n++;
   }
   cout << "Completed.\n\n";
   cout << "Displaying words that are the same in reverse\n";
   cout << "----------------------------------------------\n";
   int count = 0;
   cout << "Sending dictionary words to stack for reversal...\n\n";
   for(int i = 0; i < 52875; i++){
        strcpy(word, arr[i]);
        if(strlen(word) >= 3){
            for(unsigned int i = 0; i < strlen(word); i++){
                s.push(word[i]);
            }
            strcpy(tmp, word);
            for(unsigned int i = 0; i < strlen(word); i++){
                tmp[i] = s.pop();
            }
            if(strcmp(word, tmp) == 0){
                cout << word << ", ";
                if(count == 20){
                    cout << "\n";
                    count = 0;
                }
                count++;
            }
        }
   }
   fin.close();
   cout << "Dictionary read.\n";
   cout << "\n";
   cout << "Done.\n\n";
   return 0;
}


