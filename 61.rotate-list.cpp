/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        ListNode *tmp = head;
        int length = 1;
        while (tmp->next) {
            tmp = tmp->next;
            ++length;
        }
        ListNode *tail = tmp;
        k %= length;
        if (k == 0) {
            return head;
        }
        k = length - k;
        k %= length;
        tmp = head;
        while (--k) {
            tmp = tmp->next;
        }
        tail->next = head;
        head = tmp->next;
        tmp->next = nullptr;
        return head;
    }
};

