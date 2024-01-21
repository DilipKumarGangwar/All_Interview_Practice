//Implementation of Custom Map Class using AVL tree
#include <iostream>
using namespace std;

template <typename T,typename U>
struct Node
{
    T key;
    U value;
    Node<T,U>* left,*right;
    int height;

    Node(T key,U value)
    {
        this->key = key;
        this->value=value;
        left = nullptr;
        right= nullptr;
        height=1;
    }
};

template <typename T,typename U>
class Map
{
    Node<T,U>* root;
    int counter;
    int getHeight(Node<T,U> * node)
   {
     if(node == nullptr)
        return 0;
     return node->height;   
   }

    int getBalanceFactor(Node<T,U> * node)
    {
        if(node == nullptr)
        return 0;
        return getHeight(node->left) - getHeight(node->right);

    }

    Node<T,U>* leftRotate(Node<T,U>* ptrToImbalanceNode)
    {
        Node<T,U>* x = ptrToImbalanceNode->right;
        Node<T,U>* y = x->left; //because y will break

        //join
        x->left = ptrToImbalanceNode;
        ptrToImbalanceNode->right = y;
        
        //after rotation update height
        //1. Update  imbalnacenode->height then x->height 
        ptrToImbalanceNode->height = 1 + max(getHeight(ptrToImbalanceNode->left), getHeight(ptrToImbalanceNode->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right)) ;
    
        return x;
    }


    Node<T,U>* rightRotate(Node<T,U>* ptrToImbalanceNode)
    {
        Node<T,U>* x = ptrToImbalanceNode->left;
        Node<T,U>* y = x->right; //because y will break

        //join
        x->right = ptrToImbalanceNode;
        ptrToImbalanceNode->left = y;
        
        //after rotation update height
        //1. Update  imbalnacenode->height then x->height 
        ptrToImbalanceNode->height = 1 + max(getHeight(ptrToImbalanceNode->left), getHeight(ptrToImbalanceNode->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right)) ;
    
        return x;

    }



    Node<T,U> * insertUtil( Node<T,U>* root,T key,U value)
    {
        //here only I will insert node 
        //Check whick of the four cases are there
        //And call the appropriate rotation - Left Rotate, right rotate or mix of them
        
        if(root== nullptr)
        {
          counter++;  
          return new Node<T,U>(key,value);
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
    void printInOrderUtil(Node<T,U>* root)
    {
            if (root != nullptr) {
                printInOrderUtil(root->left);
                cout << root->key << " "<<root->value << endl;
                printInOrderUtil(root->right);
            }
    }

    Node<T,U>* iterator(T key)
    {
        Node<T,U> * temp = root;
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
    
    void insert(T key,U value)
    {
       this->root= insertUtil(this->root,key,value);
    }
    void printInOrder()
    {
            printInOrderUtil(this->root);
    }  

    Node<T,U>* getRoot()
    {
        return root;
    }
    int size()
    {
        return counter;
    }
    
    Node<T,U>* find(T key)
    {
         return iterator(key);
    }


};



int main() {
    
    int choice;
    int key;
    float value;
    //Node * root= nullptr; 
    Map<int,float> mapRoot;
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
                 Node<int,float>* ptr = mapRoot.find(key);
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