//Given the head of a linked list, reverseSubList the nodes of the list k at a time,
//and return the modified list. 
//
// k is a positive integer and is less than or equal to the length of the 
//linked list. If the number of nodes is not a multiple of k then left-out nodes, in 
//the end, should remain as it is. 
//
// You may not alter the values in the list's nodes, only nodes themselves may 
//be changed. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]
// 
//
// Example 2: 
// 
// 
//Input: head = [1,2,3,4,5], k = 3
//Output: [3,2,1,4,5]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is n. 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
// Follow-up: Can you solve the problem in O(1) extra memory space? 
//
// Related Topics Linked List Recursion 👍 12249 👎 611


#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
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
    // head 为前驱，tail为后继
    // 返回子链反转后的下一次调用时，head应该具有的值
    ListNode *reverseSubList(ListNode *head, ListNode *tail) {
        // k >= 1 则head.next一定为not null
        ListNode *p = head->next->next, *pre = head->next;
        ListNode *e = pre;
        while (p != tail) {
            ListNode *t = p;
            p = p->next;
            t->next = pre;
            pre = t;
        }
        head->next = pre;
        e->next = tail;
        return e;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pre = new ListNode(0, head);
        ListNode *p1 = pre, *p2 = head;
        int idx = 0;
        while (p2) {
            p2 = p2->next;
            if (++idx == k) {
                idx = 0;
                p1 = reverseSubList(p1, p2);
            }
        }
        ListNode *ret = pre->next;
        delete pre;
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
