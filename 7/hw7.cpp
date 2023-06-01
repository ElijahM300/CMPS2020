//Elijah Morris
//Homework 7 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const char filename[] = "/usr/share/dict/cracklib-small";

class HashTable{
private:
    string *arr;
    int size;
    int n;
public:
    HashTable(int sz){
        //initial size of the hash table.
        arr = new string[sz];
        for(int i = 0; i < sz; i++)
            arr[i] = "-null-";
        size = sz;
        n = 0;
    }
    int hash1(string word){
        int sum = 0;
        for(unsigned int i = 0; i <= word.size(); i++)
            sum = sum + word[i];
        return (sum % size);
    }
    double loadFactor(){
        return (double)n/(double)size;
    }
    void insert(string word){
        //No duplicates are allowed in a hash table!
        int idx = hash1(word);
        if(arr[idx] == "-null-"){ 
            arr[idx] = word;
            n++;
            if(loadFactor() >= 0.7){
                resizeTable();
            }
        }
        else{
            //collision
            //linear probe for available cell
            int j = idx + 1;
            for(int i = 0; i < size; i++){
                if(arr[j] == word){
                    //Duplicate found!
                    break;
                }
                else if(arr[j] == "-null-"){
                    //found a spot
                    arr[j] = word;
                    n++;
                    if(loadFactor() >= 0.7){
                        resizeTable();
                    }
                    break;
                }
                j = (j + 1) % size;
            }
        }
    }
    void search(string word){
        int idx = hash1(word);
        int j = idx;
        for(int i = 0; i < size; i++){
            if(arr[j] == word){
                cout << "The word was found at index " << j << endl;
                return;
            }
            else if(arr[j] == "-deleted-"){
                //keep searching
            }
            else if(arr[j] == "-null-"){
                cout << "The word was not found\n";
                return;
            }
            j = (j + 1) % size;
        }
    }
    void remove(string word){
        int idx = hash1(word);
        int j = idx;
        for(int i = 0; i < size; i++){
            if(arr[j] == word){
                arr[j] = "-deleted-";
                n--;
                return;
            }
            else if(arr[j] == "-deleted-"){
                //keep searching
            }
            else if(arr[j] == "-null-"){
                return;
            }
            j = (j + 1) % size;
        }
    }
    void resizeTable(){
        string *old_arr = arr;
        int old_size = size;
        size = (int)(size * 2.0);
        for(int j = 2; j <= size/2; j++){
            if(size % j == 0)
                size++;
        }
        arr = new string[size];
        for(int j = 0; j < size; j++){
            arr[j] = "-null-";
        }
        //insert all values
        n = 0;
        for(int i = 0; i < old_size; i++){
            insert(old_arr[i]);
        }
        //delete old array
        cout << "resizeTable() new size: " << size << endl;
        delete [] old_arr;
    }
    void showTable(){
        for(int i = 0; i < size; i++)
           cout << i << " " << arr[i] << endl;
        cout << "\n";
        cout << "Size: " << size << endl;
        cout << "n: " << n - 2  << endl;
        cout << "Load factor: " << (double)(n - 2)/(double)size << endl;
        cout << "\n\n"; 
    }
    int getSize(){
        return size;
    }
};

int main(){
    int tableSize;
    unsigned int length;
    string text;
    string wordSearch;
    string wordDelete;
    cout << "Homework 7\n";
    cout << "Hash table of words from the dictionary\n\n";
    cout << "Initial table size: ";
    cin >> tableSize;
    cout << "Enter the length of English words to be hashed: ";
    cin >> length;
    cout << "\n";
    cout << "Creating hash table.\n";
    HashTable h(tableSize);
    cout << "Hash table initial size: " << tableSize << endl;
    cout << "\n";
    cout << "Inserting words from the file: " << filename << endl;
    ifstream fin;
    fin.open(filename);
    if(fin.fail()){
        cout << "ERROR! Could not open file " << filename << endl;
        exit(0);
    }
    while(!fin.eof()){
        fin >> text;
        if(h.getSize() <= 17 && text.size() == length){
            h.insert(text);
        }
    }
    fin.close(); 
    cout << "Hash table...\n";
    h.showTable();
    cout << "Search for word: ";
    cin >> wordSearch;
    h.search(wordSearch);
    cout << "Delete word: ";
    cin >> wordDelete;
    h.remove(wordDelete);
    cout << "Notice: word deleted\n";
    cout << "Hash table...\n";
    h.showTable();
    return 0;
}











