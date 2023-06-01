//Elijah Morris

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    cout << "Number of arguments: " << argc << endl;
    if(argc > 1){
        cout << "filename: " << argv[1] << endl;
        //open the file, read the words
        //search for each word
    }
    else{
        char w[100];
        cout << "What is your word? ";
        cin >> w;
        //now search for the user's word
    }
    cout << endl;
    return 0;
}
