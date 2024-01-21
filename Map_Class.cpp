#include <iostream>
using namespace std;

struct Node
{
    int key,value;
    Node * left,*right;
    int height;

    Node(int key,int value)
    {
        cout<<"dsf ";
        this->key = key;
        this->value=value;
        left = nullptr;
        right= nullptr;
        height=1;
    }
};


class Map
{
    Node* root;
    int counter;
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



    Node * insertUtil( Node* root,int key,int value)
    {
        //here only I will insert node 
        //Check whick of the four cases are there
        //And call the appropriate rotation - Left Rotate, right rotate or mix of them
        
        if(root== nullptr)
        {
          counter++;  
          return new Node(key,value);
        }
        if(root->key == key)
        {
            cout<<"Key "<<key<<" already in map"<<endl;
          return root;
        }
        if(key > root->key) //go right
        root->right= insertUtil(root->right,key,value);
        else if(key < root->key)
        root->left= insertUtil(root->left,key,value);
        
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
                cout << root->key << " "<<root->value << endl;
                printInOrderUtil(root->right);
            }
    }

    Node* iterator(int key)
    {
        Node * temp = root;
        while(temp!= nullptr)
        {
            if(temp->key == key)
               return temp;
            else if(key > temp->key)   //left
               temp=temp->right;
            else
               temp=temp->left;    
        }
        return nullptr;
    }

     
    public:

    public:
    Map()
    {
        root=nullptr;
        counter=0;
    }
    
    void insert(int key,int value)
    {
       this->root= insertUtil(this->root,key,value);
    }
    void printInOrder()
    {
            printInOrderUtil(this->root);
    }  

    Node* getRoot()
    {
        return root;
    }
    int size()
    {
        return counter;
    }
    
    Node* find(int key)
    {
         return iterator(key);
    }


};



int main() {
    
    int choice, key,value;
    //Node * root= nullptr; 
    Map mapRoot;
    do {
        cout << "Menu:\n";
        cout << "1. Insert a number into BST\n";
        cout << "2. Print the BST\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enterr key,val to insert into map: ";
                cin >> key>>value;
                mapRoot.insert(key,value);
                cout<<"Root="<<mapRoot.getRoot()<<endl;
                break;

            case 2:
                mapRoot.printInOrder();
                break;
            case 3:
                cout<<"Map size "<<mapRoot.size()<<endl;
                break;
             case 4:
                 {
                 cout<<"Enter key to find "<<endl;
                 cin>>key;
                 Node* ptr = mapRoot.find(key);
                 if(ptr == nullptr)
                    cout<<"Key not exists "<<endl;
                 else
                    cout<<" Key found havng value ="<<ptr->value<<endl;   
                break; 
                 }   
            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}