//Elijah Morris
//Homework 6 Program
//2-27-20

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool checkOrder(string words[], int size);
int storeInArray(ifstream &fin, string words[]);
void selectionSort(string words[], int size);
int binarySearch(string words[], int size, string input);
int binarySearch2(string words[], int size, string text);
const char filename[] = "/usr/share/dict/cracklib-small";

int main(int argc, char *argv[]){
    string words[52875];
    string input;
    string text;
    cout << "Homework 6\n";
    cout << "Search for words in a dictionary using binary search.\n\n";
    ifstream fin;
    fin.open(filename);
    if(fin.fail()){
        cout << "ERROR! Could not open file " << filename << endl;
        exit(0);
    }
    //ifstream win;
    //win.open(argv[1]);
    //if(win.fail()){
       // cout << "ERROR! Could not open file " << argv[1] << endl;
       // exit(0);
    //}
    int numOfWords = storeInArray(fin, words);
    cout << numOfWords << " words found.\n";
    if(checkOrder(words, 52875) == false){
        cout << "Out of order.\n";
        cout << "Sorting now, please wait...\n";
        selectionSort(words, 52875);
        cout << "Sort complete!\n";
        cout << "In order.\n";
    }
    else 
        cout << "In order.\n";
    cout << "\n";
    if(argc > 1){
        ifstream win;
        win.open(argv[1]);
        if(win.fail()){
            cout << "ERROR! Could not open file " << argv[1] << endl;
            exit(0);
        }
        cout << "Reading text file: " << argv[1] << endl;
        cout << "nn = how many compares were needed.\n";
        while(!win.eof()){
            win >> text;
            if(binarySearch2(words, 52875, text) == -1)
                cout << "   " << text << endl; 
            else
                cout << binarySearch2(words, 52875, text) << " " << text << endl;
        }
        win.close();
        cout << "\n";
        cout << "Done.\n";
    }
    else{
        cout << "Please enter a word: ";
        cin >> input;
        if(binarySearch(words, 52875, input) == -1)
            cout << "Sorry, the word was not found\n";
        else
            cout << input << " was found at index " << binarySearch(words, 52875, input);
        fin.close();
        cout << "\n\n";
        cout << "Done.\n";
    }
    return 0;
}
bool checkOrder(string words[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(words[j] > words[j + 1])
                return false;
        }
    }
    return true; 
}
int storeInArray(ifstream &fin, string words[]){
    string dictWord;
    int n = 0;
    while(n < 52875){
        fin >> dictWord;
        words[n] = dictWord;
        n++;
    }
    return n;
}
void selectionSort(string words[], int size){
    for(int i = 0; i < size; i++){
        int index = i;
        for(int j = i + 1; j < size; j++){
            if(words[j] < words[index]){
                index = j;
            }
        }
        if(index != i){
            string tmp = words[i];
            words[i] = words[index];
            words[index] = tmp;
        }
    }
}
int binarySearch(string words[], int size, string input){
    int start = 0;
    int end = size - 1;
    int mid;
    do{
        mid = (start + end)/2;
        if(words[mid] == input)
            return mid;
        else if(words[mid] < input)
            start = mid + 1;
        else    
            end = mid - 1;
    }while(start <= end);
    return -1;
}
int binarySearch2(string words[], int size, string text){
    int start = 0;
    int end = size - 1;
    int mid;
    int count = 0;
    do{
        mid = (start + end)/2;
        if(words[mid] == text){
            count++;
            return count;
        }
        else if(words[mid] < text)
            start = mid + 1;
        else    
            end = mid - 1;
        count++;
    }while(start <= end);
    return -1;
}





