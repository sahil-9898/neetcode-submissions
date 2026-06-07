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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        while (curr && n<k) {
            n++;
            curr = curr->next;
        }
        if (n == k) {
            curr = reverseKGroup(curr, k);
            while (n>0) {
                n--;
                ListNode* next = head->next;
                head->next = curr;
                curr = head;
                head = next;
            }
            head = curr;
        }
        return head;
    }
};
