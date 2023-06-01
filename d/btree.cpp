#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(){
        left = right = NULL;
    }
    Node(int value){
        data = value;
        left = right = NULL;
    }
};
class BST{
    Node *root;
public:
    BST(){
        root = NULL;
    }
    ~BST(){
        cleanupNodes(root);
    }
    void cleanupNodes(Node *node){
        if(node == NULL)
            return;
        cleanupNodes(node->left);
        cleanupNodes(node->right);
        delete node;
    }
    void insert(Node *&root, Node *newnode){
        //base case
        if(root == NULL){
            root = newnode;
            return;
        }
        if(newnode->data < root->data)
            insert(root->left, newnode);
        else if(newnode->data > root->data)
            insert(root->right, newnode);            
    }
    void insertValue(int value){
        Node *newnode = new Node(value);
        insert(root, newnode);   
    }    
    void display(Node *node, int level){
        if(node == NULL)
            return;
        display(node->right, level + 1);
        cout << setw(level*3 + 1) << node->data << endl;
        display(node->left, level + 1);

    }
    void displayTree(){
        display(root, 0);
        cout << endl;
    }
    void makeDeletion(Node *&node){
        Node *tmpNode = NULL;
        if(node == NULL)
            return;
        else if(node->right == NULL){
            tmpNode = node;
            node = node->left;
            delete tmpNode;
        }
        else if(node->left == NULL){
            tmpNode = node;
            node = node->right;
            delete tmpNode;
        }
        else{
            tmpNode = node->right;
            while(tmpNode->left)
                tmpNode = tmpNode->left;
            tmpNode->left = node->left;
            tmpNode = node;
            node = node->right;
            delete tmpNode;
        }
    }
    void deleteNode(int value, Node *&node){
        if(value < node->data)
            deleteNode(value, node->left);
        else if(value > node->data)
            deleteNode(value, node->right);
        else
            makeDeletion(node);
    }
    void remove(int value){
        deleteNode(value, root);
    }
    int countNodes(Node *node){
        if(node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);

    }   
    int countOfNodes(){
        return countNodes(root);
    }
    int countLevels(Node *node){
        if(node == NULL)
            return 0;
        return 1 + max(countLevels(node->left), countLevels(node->right));
    }
    int countOfLevels(){
        return countLevels(root);
    }
    int countLeafNodes(Node *node){
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right == NULL)
            return 1 + countLeafNodes(node->left) + countLeafNodes(node->right);
        else
            return countLeafNodes(node->left) + countLeafNodes(node->right);
    }
    int countOfLeafNodes(){
        return countLeafNodes(root);
    }
    int countOneChildNodes(Node *node){
        if(node == NULL)
            return 0;
        if((node->left != NULL  &&  node->right == NULL) || 
            (node->right != NULL && node->left == NULL))
            return 1 + countOneChildNodes(node->left) + countOneChildNodes(node->right);
        else
            return countOneChildNodes(node->left) + countOneChildNodes(node->right);
    }
    int countOfOneChildNodes(){
        return countOneChildNodes(root);
    }
    bool searchNode(int value){
        Node *node = root;
        while(node){
            if(node->data == value){
                return node;
            }
            else if(value < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return NULL;
    }
    void clear(){
        clearTree(root);
    }
    void clearTree(Node *node){
        if(node == NULL)
            return;
        delete node;
        clearTree(node->left);
        node->left = NULL;
        clearTree(node->right);
        node->right = NULL;
        root = NULL;
    }
    void preOrder(){
        preOrderTraversal(root);
    }
    void preOrderTraversal(Node *node){
        if(node == NULL)
            return;
        cout << node->data << endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    void inOrder(){
        inOrderTraversal(root);
    }
    void inOrderTraversal(Node *node){
        if(node == NULL)
            return;
        inOrderTraversal(node->left);
        cout << node->data << endl;
        inOrderTraversal(node->right);
    }
    void postOrder(){
        postOrderTraversal(root);
    }
    void postOrderTraversal(Node *node){
        if(node == NULL)
            return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << endl;
    }
};

int main(){
    srand(time(NULL));
    BST bst;
    int num;
    int n;
    char input;
    do{
        cout << " Lab 13 Binary Tree Operations\n";
        cout << " ------------------------------\n";
        cout << " 1. Clear the binary tree\n";
        cout << " 2. Insert a value\n";
        cout << " 3. Insert several (n) random values\n";
        cout << " 4. Display tree (graphical)\n";
        cout << " 5. Delete a value\n";
        cout << " 6. Show all traversals\n";
        cout << " 7. Show statistical counts\n";
        cout << " 8. Search the binary tree\n";
        cout << " q. End program\n";
        cout << " ------------------------------\n";
        cout << " Select option: ";
        cin >> input;
        cout << "\n";
        switch(input){
            case '1':
                cout << "Clearing the binary tree...\n";
                bst.clear();
                cout << "The tree was cleared successfully\n\n";
                break;
            case '2':
                cout << "Insert a node...\n";
                cout << "Enter a value to insert: ";
                cin >> num;
                bst.insertValue(num);
                cout << "Value was inserted.\n\n";
                break;
            case '3':
                cout << "Insert several (n) random values...\n";
                cout << "How many values to insert?: ";
                cin >> n;
                for(int i = 0; i < n; i++)
                    bst.insertValue(rand()%50 + 1);
                cout << "Values were inserted.\n\n";
                break;
            case '4':
                cout << "Displaying the binary tree...\n\n";
                bst.displayTree();
                cout << "Tree displayed successfully.\n\n";
                break;
            case '5':
                cout << "Delete a value...\n";
                cout << "Enter a value to delete: ";
                cin >> num;
                bst.remove(num);
                cout << "Value was deleted.\n\n";
                break;
            case '6':
                cout << "Show all traversals...\n";
                cout << "Pre-order traversal:\n";
                bst.preOrder();
                cout << "\n";
                cout << "In-order traversal:\n";
                bst.inOrder();
                cout << "\n";
                cout << "Post-order traversal:\n";
                bst.postOrder();
                cout << "\n";
                break;
            case '7':
                cout << "Statistical counts...\n";
                cout << "Count of nodes in the tree: ";
                cout << bst.countOfNodes();
                cout << "\n\n";
                cout << "Count of levels in the tree: ";
                cout << bst.countOfLevels();
                cout << "\n\n";
                cout << "Count of leaf-nodes in the tree: ";
                cout << bst.countOfLeafNodes();
                cout << "\n\n";
                cout << "Count of one child nodes in the tree: ";
                cout << bst.countOfOneChildNodes();
                cout << "\n\n";
                break;
            case '8':
                cout << "Search the binary tree...\n";
                cout << "Enter a value to search for: ";
                cin >> num;
                if(!bst.searchNode(num))
                    cout << "Sorry, the value wasn't found.\n";
                else
                    cout << "The value was found!\n";
                cout << "\n";
                break;
        }
    }while(input != 'q');
    cout << "Program is ending...\n\n";
    return 0; 
}
