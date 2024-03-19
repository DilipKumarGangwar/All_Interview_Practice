#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList
{
    Node* head, * tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data) //at last
    {
        Node* p = new  Node(data);
        if (head == nullptr)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    void deleteNode()
    {
        if (head == nullptr)
            cout << "No node to delete";
        else
        {
            Node* t = head->next;
            delete head;
            head = t;
        }
    }

    void deleteList(Node* current)
    {
        if (current->next == nullptr)
        {
            delete current;
        }
        else
        {
            deleteList(current->next);
            delete current;
        }
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        //delete the entire linked list 
        deleteList(head);
        //delete head;   
    }
};

int main()
{
    LinkedList list;
    int choice, data;

    do
    {
        cout << "\nLinked List Operations\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            list.insert(data);
            break;
        case 2:
            list.deleteNode();
            break;
        case 3:
            cout << "Linked List: ";
            list.display();
            break;
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
