/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      
     node->val = node->next->val;//copy value of next node in LL
      ListNode* temp = node->next; 
      node->next = node->next->next;//pointing next pointer
      delete temp; //delte the next node

    }
};