// class Solution
// {
//     public:
//     Node* pairWiseSwap(struct Node* head) 
//     {
//         if(head==NULL || head->next==NULL)
//          return head;
//         // The task is to complete this method
//         Node* nextPtr=NULL,*prev=NULL, *curr=head;
        
//         head= curr->next;
        
//         while(curr && curr->next)
//         {
//             nextPtr= curr->next->next;
//              if(prev != NULL)
//             {
//                 prev->next = curr->next;
//             } 
//             curr->next->next=curr;
//             prev=curr;
//             curr=nextPtr;
            
//         }    
        
//         prev->next= nextPtr;
//         return head;
        
//     }
// };





//recusrion


class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(head==NULL || head->next==NULL)
         return head;
         Node* tail = head->next;
         Node* nextPtr = tail->next; // or head->next->next
         head->next->next=head; //reverse the link
        
         head->next = pairWiseSwap(nextPtr);    
         return tail;//new head;
    }
};
