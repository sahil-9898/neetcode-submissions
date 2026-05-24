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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // find the midpoint
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse from the midpoint, this will give me 2 iterators. One from start and one from end
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev stores the last node
        second = prev;
        ListNode* first = head;

        while(second) {
            ListNode* x = first->next;
            ListNode* y = second->next;
            first->next = second;
            second->next = x;
            first = x;
            second = y;
        }
    }
};
