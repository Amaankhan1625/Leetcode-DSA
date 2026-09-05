/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

   ListNode*mergeTwoLinkedList(ListNode* list1,ListNode* list2)
    {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        
      while(list1 != nullptr && list2 != nullptr)
      {
           //sorting data
         if (list1->val <= list2->val)
         {
            temp->next = list1;
            list1 = list1->next;
        } 
        else {
            temp->next = list2;
            list2 = list2->next;
         }
        temp=temp->next;
    
    if (list1 != nullptr)
    {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
      }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
    }
    
    ListNode* middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
     
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    return slow;
    }


    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr || head->next==NULL)
            return head;
        
        
    ListNode* mid = middle(head);
    
    // Divide the list into two halves
    ListNode* right = mid->next;
    mid->next = nullptr;
    ListNode* left = head;
    
       
         // Recursively sort the left and right halves
    left = sortList(left);
    right = sortList(right);
        
    return mergeTwoLinkedList(left, right);
    }
};