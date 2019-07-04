/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// #include <map>
// #include <vector>
// #include <iostream>
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mp;
        ListNode* newHead = new ListNode(-1);
        ListNode *tmp = newHead;
        for (auto p: lists) {
            if (p) {
                mp.insert(make_pair(p->val, p));
            }
        }
        while (!mp.empty()) {
            tmp->next = new ListNode((*mp.begin()).first);
            tmp = tmp->next;
            (*mp.begin()).second = (*mp.begin()).second->next;
            if ((*mp.begin()).second) {
                mp.insert(make_pair((*mp.begin()).second->val, (*mp.begin()).second));
            }
            mp.erase(mp.begin());
        }
        tmp = newHead->next;
        delete newHead;
        return tmp;
    }
};

