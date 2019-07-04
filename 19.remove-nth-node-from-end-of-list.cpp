/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *fast = newHead, *slow = newHead;
        while (n--) {
            fast = fast -> next;
        }
        while (fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        fast = slow -> next;
        slow -> next = slow -> next -> next;
        delete fast;

        head = newHead -> next;
        delete newHead;
        return head;
    }
};

