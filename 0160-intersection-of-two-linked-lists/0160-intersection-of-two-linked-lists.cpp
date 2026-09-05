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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 =headA ;
        ListNode* l2 = headB ;
        int n = 0 ;
        int m = 0 ;


        while(l1)
        {
            l1 = l1->next ;
            n++ ;
        }

        while(l2)
        {
            l2 = l2->next ;
            m++ ;
        }

       int diff = abs(n-m) ;
       l1 = headA ;
       l2 = headB ;

     while(diff>0)
     {
        if(n>m)
        {
            l1 = l1->next ;
        }

        if(m>n)
        {
            l2 = l2->next ;
        }

        diff-- ;
     }

     while(l1 != l2)
     {
        l1 = l1->next ;
        l2 = l2->next ;
     }


     return l1 ;

    }
};