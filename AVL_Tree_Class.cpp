#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node * left,*right;
    int height;

    Node(int key)
    {
        this->key = key;
        left = nullptr;
        right= nullptr;
        height=1;
    }
};


class AVL
{
    Node* root;
    
    int getHeight(Node * node)
   {
     if(node == nullptr)
        return 0;
     return node->height;   
   }

    int getBalanceFactor(Node * node)
    {
        if(node == nullptr)
        return 0;
        return getHeight(node->left) - getHeight(node->right);

    }

    Node* leftRotate(Node* ptrToImbalanceNode)
    {
        Node* x = ptrToImbalanceNode->right;
        Node* y = x->left; //because y will break

        //join
        x->left = ptrToImbalanceNode;
        ptrToImbalanceNode->right = y;
        
        //after rotation update height
        //1. Update  imbalnacenode->height then x->height 
        ptrToImbalanceNode->height = 1 + max(getHeight(ptrToImbalanceNode->left), getHeight(ptrToImbalanceNode->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right)) ;
    
        return x;
    }


    Node* rightRotate(Node* ptrToImbalanceNode)
    {
        Node* x = ptrToImbalanceNode->left;
        Node* y = x->right; //because y will break

        //join
        x->right = ptrToImbalanceNode;
        ptrToImbalanceNode->left = y;
        
        //after rotation update height
        //1. Update  imbalnacenode->height then x->height 
        ptrToImbalanceNode->height = 1 + max(getHeight(ptrToImbalanceNode->left), getHeight(ptrToImbalanceNode->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right)) ;
    
        return x;

    }



    Node * insertUtil( Node* root,int key)
    {
        //here only I will insert node 
        //Check whick of the four cases are there
        //And call the appropriate rotation - Left Rotate, right rotate or mix of them
        
        if(root== nullptr)
        return new Node(key);
        
        if(key > root->key) //go right
        root->right= insertUtil(root->right,key);
        else if(key < root->key)
        root->left= insertUtil(root->left,key);
        
        //now caluclate height of the node ( bottom to up)
        //Also find BF , if tree is unbalanced, apply rotation 
        // else return normally w/o rotations

        root->height =  1 + max(getHeight(root->left), getHeight(root->right)) ;
        int bf = getBalanceFactor(root);

    //left left rotate
        if(bf > 1 && key < root->left->key)
        {
            cout<<"LL "<<endl;
        return rightRotate(root); //right rottae laong current root node(imbalance node)
            
        }//right right rotate
        if(bf < -1 && key > root->right->key)
        {
            cout<<"RR "<<endl;
        return leftRotate(root); //left rottae along current root node(imbalance node)
    }
        //left right rotate
        if(bf >1  && key > root->left->key)
        {
            cout<<"LR "<<endl;
            root->left=leftRotate(root->left);
        return rightRotate(root);
        }
        // right left rotate
        if(bf < -1  && key < root->right->key)
        {
            cout<<"RL "<<endl;
            root->right=rightRotate(root->right);
        return leftRotate(root);
        }

        return root;   


    }
    void printInOrderUtil(Node* root)
    {
            if (root != nullptr) {
                printInOrderUtil(root->left);
                cout << root->key << " ";
                printInOrderUtil(root->right);
            }
    }

     
    public:

    public:
    AVL()
    {
        root=nullptr;
    }
    
    void insert(int key)
    {
        this->root= insertUtil(this->root,key);
    }
    void printInOrder()
    {
            printInOrderUtil(this->root);
    }  

    Node* getRoot()
    {
        return root;
    }


};



int main() {
    
    int choice, value;
    //Node * root= nullptr; 
    AVL AVLroot;
    do {
        cout << "Menu:\n";
        cout << "1. Insert a number into BST\n";
        cout << "2. Print the BST\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enterr a number to insert into BST: ";
                cin >> value;
                AVLroot.insert(value);
                cout<<"Root="<<AVLroot.getRoot()<<endl;
                cout << value << " has been inserted into the BST.\n";
                break;

            case 2:
                AVLroot.printInOrder();
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}