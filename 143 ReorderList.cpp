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
        ListNode *tortoise = head, *hare = tortoise->next;
        while(hare && hare->next) { // Find middle node
            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        hare = tortoise;    // Split list in half
        tortoise = tortoise->next;
        hare->next = nullptr;

        ListNode *next, *prev = nullptr;    // Reverse second half
        while(tortoise) {
            next = tortoise->next;
            tortoise->next = prev;
            prev = tortoise;
            tortoise = next;
        }

        ListNode *otherHead = prev, *otherNext; // Reorder list
        while(otherHead) {
            next = head->next;
            otherNext = otherHead->next;

            head->next = otherHead;
            otherHead->next = next;

            head = next;
            otherHead = otherNext;
        }
    }
};