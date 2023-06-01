//Elijah Morris
//Lab 7 
//3-5-20

#include <iostream>
using namespace std;

class HashTable{
private:
    int *arr;
    int size;
    int n;
public:
    HashTable(int sz){
        //initial size of the hash table.
        arr = new int[sz];
        //zero value means unused
        //-1 means deleted
        for(int i = 0; i < sz; i++)
            arr[i] = 0;
        size = sz;
        n = 0;
    }
    int hash1(int value){
        return (value % size);
    }
    double loadFactor(){
        return (double)n/(double)size;
    }
    void insert(int value){
        //No duplicates are allowed in a hash table!
        int idx = hash1(value);
        if(arr[idx] == 0){ 
            arr[idx] = value;
            ++n;
            if(loadFactor() >= 0.7){
                resizeTable();
            }
        }
        else{
            //collision
            //linear probe for available cell
            int j = idx + 1;
            for(int i = 0; i < size; i++){
                if(arr[j] == value){
                    //Duplicate found!
                    break;
                }
                else if(arr[j] == 0){
                    //found a spot
                    arr[j] = value;
                    ++n;
                    if(loadFactor() >= 0.7){
                        resizeTable();
                    }
                    break;
                }
                j = (j + 1) % size;
            }
        }
    }
    void search(int value){
        int idx = hash1(value);
        int j = idx;
        for(int i = 0; i < size; i++){
            if(arr[j] == value){
                cout << "Value was found\n";
                return;
            }
            else if(arr[j] == -1){
                //keep searching
            }
            else if(arr[j] == 0){
                cout << "Value was not found\n";
                return;
            }
            j = (j + 1) % size;
        }
    }
    void remove(int value){
        int idx = hash1(value);
        int j = idx;
        for(int i = 0; i < size; i++){
            if(arr[j] == value){
                arr[j] = -1;
                --n;
                return;
            }
            else if(arr[j] == -1){
                //keep searching
            }
            else if(arr[j] == 0){
                return;
            }
            j = (j + 1) % size;
        }
    }
    void resizeTable(){
        int *old_arr = arr;
        int old_size = size;
        size = (int)(size * 1.5 + 1.0);
        arr = new int[size];
        n = 0;
        //insert all values
        for(int i = 0; i < old_size; i++){
            insert(old_arr[i]);
        }
        //delete old array
        delete [] old_arr;
    }
    void showTable(){
        cout << "Display of hash table with " << n << " elements\n";
        for(int i = 0; i < size; i++)
           cout << arr[i] << " ";
        cout << "\n";
        cout << "Load factor: " << (float)n/(float)size << endl;
        cout << "\n"; 
    }
};

int main(){
    HashTable h(7);
    h.insert(25);
    h.insert(11);
    h.insert(12);
    h.insert(5);
    h.insert(5);
    h.showTable();
    h.search(11);
    h.search(4);
    h.remove(25);
    h.showTable();
    h.insert(2);
    h.insert(9);
    h.showTable();
    h.search(11);    
    return 0;
}











