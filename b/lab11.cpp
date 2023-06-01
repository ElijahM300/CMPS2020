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
    LinkedList(LinkedList &obj){
        head = obj.head;
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
    void insert(int value, int index){
        Node *node = new Node;
        Node *tmp;
        Node *prev = nullptr;
        int count = 0;
        node->data = value;
        prev = nullptr;
        if(head == nullptr){
            head = node;
            node->next = nullptr;
        }
        else{
            tmp = head;
            prev = nullptr;
            while(tmp != nullptr && count < index){
                prev = tmp;
                tmp = tmp->next;
                count++;
            }  
            if(index == 0){
                head = node;
                node->next = tmp;
            }
            else{
                prev->next = node;
                node->next = tmp;
                
            }   
        }
    }
    void insertOrder(int value){
        Node *node = new Node;
        Node *tmp;
        Node *prev = nullptr;
        node->data = value;
        prev = nullptr;
        if(head == nullptr){
            head = node;
            node->next = nullptr;
        }
        else{
            tmp = head;
            prev = nullptr;
            while(tmp != nullptr && tmp->data < value){
                prev = tmp;
                tmp = tmp->next;
            }  
            if(prev == nullptr){
                head = node;
                node->next = tmp;
            }
            else{
                prev->next = node;
                node->next = tmp;
                
            }   
        }
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
    int getMiddle(){
        int count = 0;
        Node *node = head;
        Node *save = head;
        while(node){
            node = node->next;
            ++count;
            if(count % 2 == 0)
                save = save->next;
        }
        return save->data;    
    }
    void reverse(){
        Node *node = head;
        Node *tmp = nullptr;
        Node *prev = nullptr;
        while(node){
            tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        head = prev;
    }
    void remove(int index){
        Node *node = head;
        Node *prev = NULL;
        int count = 0;
        while(node){
            if(count == index){
                //we found it! delete it!
                //4 special cases...
                //1. we found the head node    
                if(index == 0){
                    head = node->next;
                    delete node;
                    return;
                }
                //2. we found the only node in the list
                if(index == 0 && node->next == NULL){
                    head = node->next;
                    delete node;
                    return;
                }
                //3. we found the last node
                if(node->next == NULL){
                    //previous node???
                    prev->next = NULL;
                    delete node;
                }               
                //4. we found an internal node
                else{
                    prev->next = node->next;
                    delete node;
                }

            }
            prev = node;
            node = node->next;
            count++;
        }        
    }
    int operator[](int index){
        Node *node = head;
        int count = 0;
        int value = 0;
        while(count < index){
            node = node->next;
            count++;
        } 
        value = node->data;
        return value;
    }
};

int main(){
    char input;
    int app;
    int ins;
    int del;
    int val;
    int ind;
    LinkedList l;
    LinkedList m;
    do{
        cout << "Homework 11 Linked List Operations\n";
        cout << "-----------------------------------\n";
        cout << " 1. Display linked list\n";
        cout << " 2. Append a node to the linked list\n";
        cout << " 3. Insert a node into the linked list\n";
        cout << " 4. Delete a node from the linked list\n";
        cout << " 5. Linked list copy constructor\n";
        cout << " 6. Reverse linked list\n";
        cout << " 7. Search linked list\n";
        cout << " 8. Insertion by order\n";
        cout << " 9. Overloaded [] operator\n";
        cout << " q. Quit program\n";
        cout << "-----------------------------------\n";
        cout << "Select menu option: ";
        cin >> input;
        cout << "\n";
        switch(input){
            case '1':
                cout << "Displaying the linked list...\n";
                cout << "Linked list: "; 
                l.display();
                cout << "\n";
                break;
            case '2':
                cout << "Append to the linked list...\n"; 
                cout << "Enter a number to append to the linked list: ";
                cin >> app;
                l.append(app);
                cout << "The node was successfully appended.\n";
                cout << "\n";
                break;
            case '3':
                cout << "Insert into the linked list...\n";
                cout << "Enter a number to insert and a position: ";
                cin >> ins >> ind;
                l.insert(ins, ind);
                cout << "The node was inserted successfully\n";
                cout << "\n";
                break;
            case '4':
               cout << "Delete a node from the linked list...\n"; 
               cout << "Enter a position to delete from list: ";
               cin >> del;
               l.remove(del);
               cout << "The node was successfully deleted.\n";
               cout << "\n";
               break;
            case '5':
               cout << "Copy constructor for linked list...\n";
               cout << "Copying content from linked list l to linked list m...\n";
               m = l;
               cout << "Contents of l: ";
               l.display();
               cout << "Contents of m: ";
               m.display();
               cout << "\n";
               break;
            case '6':
               cout << "Reverse the linked list...\n";
               cout << "Reversed linked list: ";
               l.reverse();
               l.display();
               cout << "\n";
               break;
            case '7':
               cout << "Search the linked list...\n";
               cout << "Enter a number to search for in the list: ";
               cin >> val;
               if(l.search(val))
                   cout << "The value was found!\n";
               else
                   cout << "The value was not found...\n";
               cout << "\n";
               break;
           case '8':
               cout << "Insert value by order...\n";
               cout << "Enter a value to insert: ";
               cin >> val;
               l.insertOrder(val);
               cout << "The value was inserted in its proper place\n";
               cout << "\n";
               break;
           case '9':
               cout << "Demonstration of the [] operator...\n";
               cout << "The value at [2] is: " << l[2] << endl;
               break;
         }

    }while(input != 'q');
    cout << "The middle value is: " << l.getMiddle() << endl;
    cout << endl;
    return 0;
}





