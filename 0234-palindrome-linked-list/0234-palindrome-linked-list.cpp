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

ListNode* reverse(ListNode* head )
{
    ListNode* curr = head ;
    ListNode* prev = nullptr ;
  

    while(curr)
    {
        ListNode* nex = nex->next ;

        curr->next = prev ;
        prev = curr ;
        curr = nex ;
     
    }

    return prev ;

    
}
    bool isPalindrome(ListNode* head) {

      if(!head || !head->next)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = reverse(slow->next);

        // Compare first half and reversed second half
        ListNode* first = head;

        while(second)
        {
            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
        
    }
};