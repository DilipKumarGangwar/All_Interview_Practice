// C++ program to implement the 
// deletion of last occurance of a number in ll
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A linked list Node
struct Node 
{
	int data;
	struct Node* next;
};

// Function to delete the last 
// occurrence
struct Node* deleteLast(struct Node* head, 
				int x)
{
	struct Node* prev = NULL,*lastOccurance=NULL,*curr=head,*currPrev=NULL;
    if(curr->data == x)
    {
      lastOccurance = prev=head;
      currPrev= head;
      curr=curr->next;
    }
  else
  {
     currPrev= head; 
     curr=curr->next;
  }
    while(curr!=NULL)
    {
       if(curr->data ==x)
       {
         lastOccurance =curr;
         prev = currPrev;
          currPrev = curr;
       }
      else
      {
           currPrev = curr;
      }
      curr=curr->next;
        
    }
      if( lastOccurance  == head) 
      {
        head=head->next;
        delete lastOccurance;
        return head;
      }
     if(lastOccurance == NULL)
        return NULL;
   //else 
   
      prev->next=lastOccurance->next;
      delete lastOccurance;
     return head;
      
	
}

// Utility function to create a new 
// node with given key 
struct Node* newNode(int x)
{
	Node* node = new Node ;
	node->data = x;
	node->next = NULL;
	return node;
}

// This function prints contents of 
// linked list starting from the given 
// Node
void display(struct Node* head)
{
	struct Node* temp = head;
	if (head == NULL)
	{
		cout << "NULL";
		return;
	}
	while (temp != NULL)
	{
		cout << temp->data << 
				" --> ";
		temp = temp->next;
	}
	cout << "NULL";
}

// Driver code
int main()
{
	struct Node* head = newNode(7);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = 
	newNode(4);
	head->next->next->next->next = 
	newNode(5);
	head->next->next->next->next->next = 
	newNode(4);
	head->next->next->next->next->next->next = 
	newNode(4);
	
	cout << "Created Linked list: ";
	display(head);
	
	// Pass the address of the head 
	// pointer
	head =deleteLast(head, 70); 
  if(head==NULL)
     cout<<"no ";
  else{
	cout << "List after deletion of 4: ";
	
	display(head); 
  }
	return 0;
}
// This code is contributed by khushboogoyal499
