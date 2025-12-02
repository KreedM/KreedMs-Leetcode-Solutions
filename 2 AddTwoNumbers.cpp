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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum = nullptr, *head = nullptr;

        int carry = 0;
        while(l1 || l2) {
            if(l1) {
                carry += l1->val;

                l1 = l1->next;
            }
            if(l2) {
                carry += l2->val;

                l2 = l2->next;
            }

            if(sum == nullptr) {
                sum = new ListNode(carry % 10);
                head = sum;
            }
            else {
                head->next = new ListNode(carry % 10);
                head = head->next;
            }
                
            carry /= 10;
        }

        if(carry)
            head->next = new ListNode(1);

        return sum;
    }
};