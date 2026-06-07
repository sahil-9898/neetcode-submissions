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
        ListNode dummy(-1, head);
        ListNode* groupPrev = &dummy;
        ListNode* groupNext = nullptr;
        while (true) {
            ListNode* kthNode = getKth(groupPrev, k);
            if (!kthNode) break;

            groupNext = kthNode->next;
            ListNode* curr = groupPrev->next;
            ListNode* prev = groupNext;
            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kthNode;
            groupPrev = tmp;
        }

        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* node, int k) {
        while (node && k > 0) {
            k--;
            node = node->next;
        }
        return node;
    }
};



