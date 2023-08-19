//You are given the head of a singly linked-list. The list can be represented 
//as: 
//
// 
//L0 → L1 → … → Ln - 1 → Ln
// 
//
// Reorder the list to be on the following form: 
//
// 
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// 
//
// You may not modify the values in the list's nodes. Only nodes themselves may 
//be changed. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
// 
//
// Example 2: 
// 
// 
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [1, 5 * 10⁴]. 
// 1 <= Node.val <= 1000 
// 
//
// Related Topics Linked List Two Pointers Stack Recursion 👍 9432 👎 312


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
    void func(ListNode *a, ListNode *b) {
        auto t = a->next;
        a->next = b;
        b->next = t;
    }
    bool cmp(ListNode *a, ListNode *b) {
        return a != b && b != a->next;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        auto it = head;
        stack<ListNode*> st;
        while (it) {
            st.push(it);
            it = it->next;
        }
        it = head;
        while (cmp(it, st.top())) {
            func(it, st.top());
            st.pop();
            if (st.top() != it) st.top()->next = nullptr;
            it = it->next->next;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
