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
        int m = 0, ret = 0, n = height.size();
        int a[n], b[n];
        for (int i = 0; i < n; ++i) {
            m = max(height[i], m);
            a[i] = m - height[i];
        }
        m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(height[n - i - 1], m);
            b[n - i - 1] = m - height[n - i - 1];
        }
        for (int i = 0; i < n; ++i) {
            ret += min(a[i], b[i]);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
