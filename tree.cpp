#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class Tree
{
    Node* root;
   void displayLeftViewUtil(Node* root,int &maxLevel,int currLevel)
{
    if(root==nullptr)
       return ;
    if(currLevel > maxLevel)
    {
        cout<<root->data<<" ";
        maxLevel= currLevel;
    }
    displayLeftViewUtil(root->left,maxLevel,currLevel+1);
    displayLeftViewUtil(root->right,maxLevel,currLevel+1);
    
}


    void inorderSuccUtil( Node* root,int key,int &ans)
    {
        // if(root==nullptr)
        //   return ;
        // inorderSuccUtil( root->right,key,ans);
        // if(root->data == key)
        //   return;
        // else if(root->data > key)
        //   ans = root->data;
        // inorderSuccUtil(root->left,key,ans);
        //  if(root==nullptr)
        //   return ;
       
        // if(key >= root->data)
        //     inorderSuccUtil(root->right,key,ans);
        // else if(key )       
        // {
        //   ans = root->data;
        //   inorderSuccUtil( root->left,key,ans);
        // }
        
        //predecessor
        if (root == nullptr)
        return;

    if (key <= root->data)
    {
        inorderSuccUtil(root->left, key, ans);
    }
    else if (key > root->data)
    {
        ans = root->data;
        inorderSuccUtil(root->right, key, ans);
    }
        
        
    }
   
public:
    Tree()
    {
        root = nullptr;
    }



     
    Node* insertUtil(Node* root, int val)
    {
        if (root == nullptr)
        {
            Node* node = new Node(val);
            return node;
        }

        if (val > root->data)
            root->right = insertUtil(root->right, val);
        else if (val < root->data)
            root->left = insertUtil(root->left, val);

        return root;
    }

    void insert(int val)
    {
        root = insertUtil(root, val);
    }

    Node* createCopy(Node* rt)
    {
        if (rt == nullptr)
        {
            return nullptr;
        }

        Node* node = new Node(rt->data);
        node->left = createCopy(rt->left);
        node->right = createCopy(rt->right);

        return node;
    }

    Tree(const Tree& other)
    {
        this->root = createCopy(other.root);
    }

    void displayUtil(Node* root)
    {
        if (root != nullptr)
        {
            displayUtil(root->left);
            cout << root->data << " ";
            displayUtil(root->right);
        }
    }

    void display()
    {
        displayUtil(root);
        cout << endl;
    }

    void TreeDelete(Node * root)
    {
         if(root == nullptr)
           return;
        //  if(root->left==nullptr && root->right == nullptr)
        //    delete root;   
        TreeDelete(root->left);
        root->left=nullptr;
        TreeDelete(root->right);
        root->right=nullptr;
        delete root;
         
        //TreeDelete(root->left);
        //TreeDelete(root->right);
      
        //delete root;
    }
    ~Tree()
    {
        cout<<"destr called ";
        TreeDelete(root);
    }
    
    void displayLeftView(int &maxLevel,int currLevel)
{
    displayLeftViewUtil(root,maxLevel,currLevel);
}

    void inorderSucc(int key)
    {
        int ans=0;
         inorderSuccUtil(root, key,ans);
         cout<<ans;
    }
};





int main()
{
    Tree obj;
    int choice, data;

    do
    {
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Copy Constructor Display\n";
        cout << "4. left view\n";
         cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            obj.insert(data);
            break;
        case 2:
            cout << "BST: ";
            obj.display();
            break;
        case 3:
        {
            Tree obj2(obj);
            cout << "Copied BST: ";
            obj2.display();
            break;
        }
        case 4:
        {
            // cout << "left view: ";
            // int maxLevel= -1,currLevel=0;
            // obj.displayLeftView(maxLevel,currLevel);
            // break;
            
            cout << "inorder succ: ";
            int key;
            cin>>key;
            obj.inorderSucc(key);
            break;
        }
        case 5:
        {
            cout << "Exiting the program.\n";
            break;
        }
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
