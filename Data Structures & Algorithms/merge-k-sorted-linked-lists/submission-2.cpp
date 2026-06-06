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
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while (first && second) {
            if (first->val < second->val) {
                curr->next = first;
                first = first->next;
            }
            else {
                curr->next = second;
                second = second->next;
            }  
            curr = curr->next;
        }
        curr->next = first ? first : second;
        return dummy.next;
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
