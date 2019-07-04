/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next) {
            ListNode* tmp = head->next;
            head->next = swapPairs(head->next->next);
            tmp->next = head;
            return tmp;
        }
        else {
            return head;
        }
    }
};

