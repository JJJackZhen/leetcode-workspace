/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        // ListNode *newHead = new ListNode(-1), *tmp = newHead;
        // while (l1 && l2) {
        //     if (l1 -> val < l2 -> val) {
        //         tmp -> next = l1;
        //         l1 = l1 -> next;
        //         tmp = tmp -> next;
        //     }
        //     else {
        //         tmp -> next = l2;
        //         l2 = l2 -> next;
        //         tmp = tmp -> next;
        //     }
        // }
        // if (l1) {
        //     tmp -> next = l1;
        // }
        // if (l2) {
        //     tmp -> next = l2;
        // }
        // tmp = newHead -> next;
        // delete newHead;
        // return tmp;
    }
};

