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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next ) return head ;

       if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Move prev to node before left
        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;

        // Reverse the required portion
        for (int i = 0; i < right - left; i++)
        {
            ListNode* nex = curr->next;

            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
        }

        return dummy.next;

    }
};