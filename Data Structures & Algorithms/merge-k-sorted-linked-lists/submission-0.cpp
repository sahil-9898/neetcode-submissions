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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        vector<int> arr;
        for(auto l: lists) {
            ListNode* head = l;
            while (head) {
                arr.push_back(head->val);
                head = head->next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* newHead = new ListNode(0);
        ListNode* temp = newHead;
        for (int i: arr) {
            temp->next = new ListNode(i);
            temp = temp->next;  
        }
        return newHead->next;
    }
};
