//insert at begin
//delet element at end of list
//search for element ( duplicates)- return all

#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node* next;
   Node* prev;
   
   Node(int data)
   {
     this->data=data;
     next=nullptr;
     prev=nullptr;
   }

};

struct TreeNode
{
   int data;
   TreeNode* left;
   TreeNode* right;
   
   TreeNode(int data)
   {
     this->data=data;
     left=nullptr;
     right=nullptr;
   }

};


Node* insert(Node* head,int element)
{
   Node *node = new Node(element);

   if(head==nullptr)
   {
    head = node;
   }
   else
   {
      node->next= head;
    //  node->prev= nullptr;

      head->prev = node;
      //shift head
      head= node;

   }
   return head;
   
}


//from last
Node* deleteElement(Node* head)
{
   if(head == nullptr)
   {
     cout<<"No node to delete";
     return head;
   }
   //go till last node
   Node* t= head;

   while(t->next!=nullptr)
   {
      t=t->next;
   }
   cout<<"Node to be deleteed="<<t->data;
   if(t==head) //1 node only
   {
         head=nullptr;
         
   }
   //delete
   else
   { 
    t->prev->next = nullptr;
    t->prev=nullptr;
   }
    delete t;
    return head;

}


void search(Node *head,int key)
{
   if(head == nullptr)
    {
        cout<<"List is empty";
        return;
    }   

    //1 or more nodes
    int count=1;
    Node* t = head;
    bool flag=false;
    while(t!=nullptr)
    {   
        if(t->data == key)
        {
           cout<<"ELemennt present at index = "<<count;
           flag=true;
        }
        count++;
        t=t->next;

    }
    if(flag ==false)
      cout<<"ELemnt not present" ;
      
}


void findMiddle(Node *head,Node** middle,Node** prev)
{
    Node* slow=head,*fast=head;
    while(fast && fast->next)
    {
        *prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    *middle = slow;
    

}

//assuming list is sorted
 TreeNode* sortedListToBST(Node* head) {
        
            if(head==nullptr)
              return nullptr;
             if(head->next==nullptr)
              return new TreeNode(head->data);  
           //find middle
           Node* middle=nullptr,*prevofMiddle=nullptr;
           findMiddle(head,&middle,&prevofMiddle);
            
            //construct tree node
            TreeNode* node = new TreeNode(middle->data);
            

            prevofMiddle->next = nullptr;

            //bhejo isko
            node->left=sortedListToBST(head);
            node->right=sortedListToBST(middle->next);
             return node;

           
    }

void displayBSTPreorder(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    displayBSTPreorder(root->left);
    displayBSTPreorder(root->right);
}


int main() {
    Node* head = nullptr; // Initialize an empty list
    TreeNode* root = nullptr; // Initialize the root of the BST

    int choice;
    int element, key;

    do {
        cout << "\n1. Insert at the beginning\n";
        cout << "2. Delete element at the end\n";
        cout << "3. Search for an element (all occurrences)\n";
        cout << "4. Display the linked list\n";
        cout << "5. Create Balanced BST\n";
        cout << "6. Display BST in Preorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                cout << "Enter the element to insert: ";
                cin >> element;
                head = insert(head, element);
                cout << "Element " << element << " inserted at the beginning.\n";
                break;
            }
            case 2:
            
                head = deleteElement(head);
                break;
        
            case 3:
             {   cout << "Enter the element to search: ";
                cin >> key;
                search(head, key);
                break;
             }
            case 4:
            {
                cout << "Linked List: ";
                Node* temp = head;
                while (temp != nullptr) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
                break;
            }
            case 5:
                cout << "Create Balanced BST" << endl;
                root = sortedListToBST(head);
                break;

            case 6:
            {
                cout << "Display BST in Preorder Traversal:" << endl;
                displayBSTPreorder(root);
                cout << endl;
                break;
            }
            case 7:
            {
                cout << "Exiting the program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 7);

    return 0;
}
