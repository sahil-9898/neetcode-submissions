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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        while (n>0) {
            temp = temp->next;
            n--;
        }
        ListNode* start = head;
        ListNode* prev = nullptr;
        while (temp) {
            prev = start;
            start = start->next;
            temp = temp->next;
        }
        if (prev == nullptr) return head->next;
        prev->next = prev->next->next;
        return head;

    }
};
