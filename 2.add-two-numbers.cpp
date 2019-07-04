/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = 0, *tmp = 0;
        bool flag = false;
        while (l1 || l2 || flag) {
            int val = flag;
            flag = false;
            if (l1) {
                val += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                val += l2 -> val;
                l2 = l2 -> next;
            }
            if (val >= 10) {
                val -= 10;
                flag = true;
            }
            if (!head) {
                head = tmp = new ListNode(val);
            }
            else {
                tmp -> next = new ListNode(val);
                tmp = tmp -> next;
            }
        }
        return head;
    }
};

