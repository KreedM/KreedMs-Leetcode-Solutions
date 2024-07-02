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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        
        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }

    /*
        ListNode *head, *node;

        if(list1) {
            if(!list2 || list1->val < list2->val) {
                node = list1;
                list1 = list1->next;
            }
            else {
                node = list2;
                list2 = list2->next;
            }
        }
        else if(list2) {
            node = list2;
            list2 = list2->next;
        }
        else
            return nullptr;

        head = node;

        while(list1 || list2) {
            if(list1) {
                if(!list2 || list1->val < list2->val) {
                    node->next = list1;
                    list1 = list1->next;
                }
                else {
                    node->next = list2;
                    list2 = list2->next;
                }
            }
            else {
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        }

        return head;
    */
    }
};