//Given a string s, return the longest palindromic substring in s. 
//
// 
// Example 1: 
//
// 
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
// 
//
// Example 2: 
//
// 
//Input: s = "cbbd"
//Output: "bb"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consist of only digits and English letters. 
// 
//
// Related Topics String Dynamic Programming 👍 26771 👎 1577


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        int n = s.size(), max = 0, ans_s = 0, ans_e = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            // 所有单个字符均为回文串
            dp[i][i] = 1;
        }
        // 第一层循环必须是右指针，否则会出现一部分的值未检测
        for (int r = 1; r < n; ++r) {
            for (int l = 0; l < r; ++l) {
                if (s[l] == s[r] && (r - l <= 2 || dp[l+1][r-1])) {
                    dp[l][r] = 1;
                    int m = r - l + 1;
                    if (m > max) {
                        ans_s = l;
                        ans_e = r;
                        max = m;
                    }
                }
            }
        }
        return s.substr(ans_s, ans_e - ans_s + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
