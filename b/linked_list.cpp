//Elijah Morris

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
class LinkedList{
    Node *head;
public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node *next;
        Node *node = head;
        while(node){
            next = node->next;
            delete node;
            node = next;
        }
    }
    void append(int value){
        //create a new node
        Node *tmp = new Node;
        //store data
        tmp->data = value;
        //adjust pointers
        tmp->next = head;
        head = tmp;
        //tmp --> head --> node --> node --> node
        //head --> node
    }
    void display(){
        Node *node = head;
        while(node){
            cout << node->data << " --> ";
            node = node->next;
        }
        cout << "null(end of list)" << endl;
    }
    bool search(int value){
        Node *node = head;
        while(node){
            if(node->data == value)
                return true;
            node = node->next;
        }
        return false;    
    }
    void remove(int value){
        Node *node = head;
        Node *prev = NULL;
        while(node){
            if(node->data == value){
                //we found it! delete it!
                //4 special cases...
                //1. we found the head node    
                if(node == head){
                    head = node->next;
                    delete node;
                    return;
                }
                //2. we found the only node in the list
                if(node == head && node->next == NULL){
                    head = node->next;
                    delete node;
                    return;
                }
                //3. we found the last node
                if(!node->next){
                    //previous node???
                    prev->next = NULL;
                    delete node;
                }               
                //4. we found an internal node
                prev->next = node->next;
                delete node;
            }
            prev = node;
            node = node->next;
        }        
    }
};

int main(){
    cout << "Homework 11 Linked List Operations\n\n";
    LinkedList l;
    l.append(25);
    l.append(35);
    l.append(75);
    l.append(175);
    l.append(-20);
    l.display();
    l.remove(75);
    l.display();
//    int val;
//    cout << "Search for what?: ";
//    cin >> val;
//    if(l.search(val))
//        cout << "Found!\n";
//    else 
//        cout << "Not Found!\n";
    cout << endl;
    return 0;
}





