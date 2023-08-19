//Given n non-negative integers representing an elevation map where the width 
//of each bar is 1, compute how much water it can trap after raining. 
//
// 
// Example 1: 
// 
// 
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [
//0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) 
//are being trapped.
// 
//
// Example 2: 
//
// 
//Input: height = [4,2,0,3,2,5]
//Output: 9
// 
//
// 
// Constraints: 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics Array Two Pointers Dynamic Programming Stack Monotonic Stack ?
//? 28123 👎 393


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1;
        int m1 = 0, m2 = 0, ret = 0;
        while (l < r) {
            m1 = max(height[l], m1);
            m2 = max(height[r], m2);
            if (height[l] < height[r]) {
                ret += m1 - height[l];
                l++;
            } else {
                ret += m2 - height[r];
                r--;
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
