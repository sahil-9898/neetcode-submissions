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
        if(lists.empty()) return nullptr;
        int n = lists.size();
        while (n > 1) {
            int half = (n+1) / 2;
            for (int i=0;i<n/2;i++) {
                lists[i] = mergeTwo(lists[i], lists[i+half]);
            }
            n = half;
        }
        return lists[0];
    }
};
