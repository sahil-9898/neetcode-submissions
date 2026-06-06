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

private:
    ListNode* mergeTwo(ListNode* first, ListNode* second) {
        if (first == nullptr) {
            return second;
        }
        if (second == nullptr) {
            return first;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* x = dummy;
        while (first || second) {
            if (first && second) {
                if (first->val < second->val) {
                    dummy->next = first;
                    first = first->next;
                }
                else {
                    dummy->next = second;
                    second = second->next;
                }
            }
            else if (first) {
                dummy->next = first;
                first = first->next;
            }
            else if (second) {
                dummy->next = second;
                second = second->next;
            }
            dummy = dummy->next;
        }
        return x->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* res = nullptr;
        for (ListNode* l: lists) {
            res = mergeTwo(res, l);
        }
        return res;
    }
};
