//You are given an array of k linked-lists lists, each linked-list is sorted in 
//ascending order. 
//
// Merge all the linked-lists into one sorted linked-list and return it. 
//
// 
// Example 1: 
//
// 
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
// 
//
// Example 2: 
//
// 
//Input: lists = []
//Output: []
// 
//
// Example 3: 
//
// 
//Input: lists = [[]]
//Output: []
// 
//
// 
// Constraints: 
//
// 
// k == lists.length 
// 0 <= k <= 10⁴ 
// 0 <= lists[i].length <= 500 
// -10⁴ <= lists[i][j] <= 10⁴ 
// lists[i] is sorted in ascending order. 
// The sum of lists[i].length will not exceed 10⁴. 
// 
//
// Related Topics Linked List Divide and Conquer Heap (Priority Queue) Merge 
//Sort 👍 17810 👎 638


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
    struct Item {
        int val;
        ListNode *ptr;
        Item(ListNode *p) : val(p->val), ptr(p) {};
        bool operator < (const Item &i) const {
            return val > i.val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<Item> h;
        int n = lists.size();
        ListNode *pre = new ListNode(), *it = pre;
        for (int i = 0; i < n; ++i) {
            if (lists[i]) h.emplace(lists[i]);
        }
        while (!h.empty()) {
            ListNode *min = h.top().ptr;
            it->next = min;
            it = it->next;
            if (min->next) h.emplace(min->next);
            min->next = nullptr;
            h.pop();
        }
        ListNode *ans = pre->next;
        delete pre;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
