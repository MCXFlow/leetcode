//Given a signed 32-bit integer x, return x with its digits reversed. If 
//reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ -
// 1], then return 0. 
//
// Assume the environment does not allow you to store 64-bit integers (signed 
//or unsigned). 
//
// 
// Example 1: 
//
// 
//Input: x = 123
//Output: 321
// 
//
// Example 2: 
//
// 
//Input: x = -123
//Output: -321
// 
//
// Example 3: 
//
// 
//Input: x = 120
//Output: 21
// 
//
// 
// Constraints: 
//
// 
// -2³¹ <= x <= 2³¹ - 1 
// 
//
// Related Topics Math 👍 11211 👎 12506


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reverse(int x) {
        long long ans = 0, a = x;
        bool f = false;
        if (x<0) {
            f= true;
            a=-(long long)x;
            // 使用long long a = x和a = - (long long)x为了避免UBSan
        }
        while (a) {
            int t = a % 10;
            a /= 10;
            ans = ans * 10 +t;
        }
        if (f) ans=-ans;
        if (ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
