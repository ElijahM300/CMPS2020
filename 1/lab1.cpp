//Elijah Morris
//1-23-20
//Lab 1
#include <iostream>
#include <cstring>
using namespace std;
void primeNumbers();
void summation();
void coinToss(int coinTosses);
void hashTable();
void lookForCSUB();
void linkedList();

int main(){
    srand(time(NULL));
    char input;
    int numOfTosses;
    do{
        cout << "Lab-1 Menu of options\n";         
        cout << "----------------------\n";
        cout << "  1. Prime number digit\n";
        cout << "  2. Summation - 1000 times\n";
        cout << "  3. Coin flip\n";
        cout << "  4. Hash table\n";
        cout << "  5. Look for CSUB\n";
        cout << "  6. Linked-list operations\n";
        cout << "  q. Quit the program\n";
        cout << "----------------------\n";
        cout << "Select menu option: ";
        cin >> input;
        switch(input){
            case '1':
                cout << "\n";
                primeNumbers();
                break;
            case '2':
                cout << "\n";
                summation();
                break;
            case '3':
                cout << "\n";
                do{
                    cout << "How many coin tosses?: ";
                    cin >> numOfTosses;
                    coinToss(numOfTosses);
                }while(numOfTosses != 0);
                break;
            case '4':
                cout << "\n";
                hashTable();
                break;
            case '5':
                cout << "\n";
                lookForCSUB();
                break;
            case '6':
                cout << "\n";
                linkedList();
                break;
        }
    }while(input != 'q');
    cout << "\n";

    return 0;
}

void primeNumbers(){
    int digit;
   // bool prime = true;
    cout << "List prime numbers whose rightmost digit is given by the user\n";
    cout << "-------------------------------------------------------------\n";
    cout << "\n";
    cout << "Please enter a single digit: ";
    cin >> digit;
    cout << "\n";
    cout << "Primes: ";
   // for(int i = 2; i < digit; i++){
       // if(num % i == 0)
     //       prime = false;
     //   else if(num % 10 == digit){
     //       prime = true; 
     //   }
   // }
   // if(prime)
   //     
    cout << "\n\n";
}
void summation(){
    int number = 0;
    cout << "Summation 1000 times\n";
    cout << "--------------------\n";
    cout << "\n";
    cout << "Summation to what number?: ";
    cin >> number;
    int sum = 0;
    int j = 0;
    int k = 0;
    cout << "Calculating now...\n";
    for(int i = 0; i < 10; i++){
        while(j < 10){
            do{
                for(int l = 1; l <= number; l++){
                    sum = sum + l;
                }
                k++;
            }while(k < 10);
            j++;
        }
    }
    cout << "Calculation complete.\n";
    cout << "\n";
    cout << "The sum is: " << sum << endl;
    cout << "\n";
}
void coinToss(int numOfTosses){
    static int heads = 0;
    static int tails = 0;
    int random;
    if(numOfTosses == 0){
        cout << "\n";
        cout << "Game over. Thanks.\n";
    }
    for(int i = 0; i < numOfTosses; i++){
        random = rand()%2;
        if(random == 0)
            heads = heads + 1;
        else if(random == 1)
            tails = tails + 1;
    }
    if(numOfTosses > 0){
        cout << "Heads: " << heads << endl;
        cout << "Tails: " << tails << endl;
    }
    cout << "\n";
}
void hashTable(){
    int index = 0;
    int arr[100] = {0};
    cout << "Hash table\n";
    cout << "----------\n\n";
    cout << "Generating randoms now...\n";
    do{
        index = rand()%61 + 20;
        ++arr[index];
        if(arr[index] > 20){
            cout << "Finished\n\n";
        }
    }while(arr[index] <= 20);
    cout << "Indexes asked for: ";
    for(int i = 0; i < 100; i++){
        if(arr[i] > 20 || (arr[i] >= 1 && arr[i] <= 5))
            cout << i << " ";
    }
    cout << "\n\n";
}
void lookForCSUB(){
    char str[11];
    int count = 0;
    int found = 0;
    str[10] = '\0';
    cout << "Trying now...\n\n";
    do{
        for(int i = 0; i < 10; i++){
            str[i] = rand()%26 + 'A'; 
        }
        ++count;
        char save = str[4];
        str[4] = '\0';
        if(strcmp(str, "CSUB") == 0)
            found = 1;
        str[4] = save;
    }while(!found);
    cout << "Found it in " << count << " tries.\n\n";
    cout << "Here is the string: " << str << endl;
    cout << "\n";
}
void linkedList(){
    struct Node{
        int data;
        Node *next;
        Node(){ data = 0; next = NULL; }
    };
    cout << "Linked-list\n";
    cout << "\n";
    cout << "Declaring nodes now.\n";
    Node n1, n2, n3;
    cout << "Stepping through linked list now.\n";
    cout << "\n";
    n1.data = 1;
    n2.data = 2;
    n3.data = 3;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;
    Node *p = &n1;
    cout << "Data values are: ";
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << "\n\n";
    cout << "Freeing node memory.\n";
    cout << "Done.\n\n";
}





