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
        ListNode *normal = head, *delayed = nullptr;
        
        while(normal->next) {
            normal = normal->next;
            
            if(n == 0)
                delayed = delayed->next;
            else if(--n == 0)
                delayed = head;
        }

        if(delayed)
            delayed->next = delayed->next->next;
        else
            head = head->next;

        return head;
    }
};