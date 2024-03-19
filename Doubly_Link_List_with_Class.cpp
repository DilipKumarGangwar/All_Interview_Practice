//insert at begin
//delet element at end of list
//search for element ( duplicates)- return all

#include <iostream>
using namespace std;

class Node
{
  
   int data;
   Node* next;
   Node* prev;
   
   public:
   Node(int data)
   {
     this->data=data;
     next=nullptr;
     prev=nullptr;
   }
   Node* getPrev()
   {
       return prev;
   }
   Node* getNext()
   {
       return next;
   }
   void setPrev(Node* node)
   {
        this->prev=node;
   }
   void setNext(Node* node)
   {
        this->next=node;
   }

    int getData()
   {
        return data;
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
     // node->next= head;
     node->setNext(head);   

     // head->prev = node;
     head->setPrev(node);
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

//    while(t->next!=nullptr)
//    {
//       t=t->next;
//    }

      while(t->getNext()!=nullptr)
     {
        t=t->getNext();
      }
   cout<<"Node to be deleteed="<<t->getData();
   if(t==head) //1 node only
   {
         head=nullptr;
         
   }
   //delete
   else
   { 
     t->getPrev()->setNext(nullptr);
     t->setPrev(nullptr);
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
        if(t->getData() == key)
        {
           cout<<"ELemennt present at index = "<<count;
           flag=true;
        }
        count++;
        t=t->getNext();

    }
    if(flag ==false)
      cout<<"ELemnt not present" ;
      
}

int main() {
    Node* head = nullptr; // Initialize an empty list

    int choice;
    int element, key;

    do {
        cout << "\n1. Insert at the beginning\n";
        cout << "2. Delete element at the end\n";
        cout << "3. Search for an element (all occurrences)\n";
        cout << "4. Display the linked list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                head = insert(head, element);
                cout << "Element " << element << " inserted at the beginning.\n";
                break;

            case 2:
                head = deleteElement(head);
                break;

            case 3:
                cout << "Enter the element to search: ";
                cin >> key;
                search(head, key);
                break;

            case 4:
            {
                cout << "Linked List: ";
                Node* temp = head;
                while (temp != nullptr) {
                   // cout << temp->data << " ";
                    //temp = temp->next;
                      cout << temp->getData() << " ";
                    temp = temp->getNext();
                }
                cout << endl;
                break;
            }
            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    

    return 0;
}




