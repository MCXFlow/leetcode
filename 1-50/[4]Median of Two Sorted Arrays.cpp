//Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
//the median of the two sorted arrays. 
//
// The overall run time complexity should be O(log (m+n)). 
//
// 
// Example 1: 
//
// 
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
// 
//
// Example 2: 
//
// 
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
//
// 
// Constraints: 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
//
// Related Topics Array Binary Search Divide and Conquer 👍 24678 👎 2740


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 一种时间复杂度为O(m+n)的解法
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // f为合并后是否为奇数个 c为计数
        // p指向当前合并后的位置来自哪个数组 v是当前合并后数组该位置的值
        int p1 = 0, p2 = 0, f = (n1 + n2) % 2, c = 0;
        int v, pv, r = 0;
        while (p1 < n1 || p2 < n2) {
            if (p1 < n1 && p2 < n2) {
                v = min(nums1[p1], nums2[p2]);
                v == nums1[p1] ? p1++ : p2++;
            } else {
                if (p1 == n1) {
                    v = nums2[p2];
                    p2++;
                } else {
                    v = nums1[p1];
                    p1++;
                }
            }
            if (c++ == (n1 + n2)/2) {
                return double ((f ? v : pv) + v) / 2;
            }
            pv = v;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
