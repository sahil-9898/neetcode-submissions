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
        ListNode* x = l1;
        ListNode* y = l2;

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (x || y) {
            int a = x == nullptr ? 0 : x -> val;
            int b = y == nullptr ? 0 : y -> val;

            int sum = a + b + carry;
            int res = sum % 10;
            carry = sum / 10;
            
            temp->next = new ListNode(res);
            temp = temp -> next;
            if (x) x = x -> next;
            if (y) y = y -> next;
        }

        if (carry > 0) {
            temp -> next = new ListNode(carry);
        }
        ListNode* resHead = dummy->next;
        delete(dummy);
        return resHead;
    }
};
