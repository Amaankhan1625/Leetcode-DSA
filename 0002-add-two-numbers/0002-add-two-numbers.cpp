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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* prev = nullptr;

        int carry = 0;

        while (head1 || head2) {

            int sum = carry;

            if (head1)
                sum += head1->val;

            if (head2)
                sum += head2->val;

            carry = sum / 10;

            if (head1) {
                head1->val = sum % 10;
                prev = head1;
                head1 = head1->next;
            }
            else {
                // l1 ended, so attach a new node
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
            }

            if (head2)
                head2 = head2->next;
        }

        if (carry)
            prev->next = new ListNode(carry);

        return l1;
    }
};