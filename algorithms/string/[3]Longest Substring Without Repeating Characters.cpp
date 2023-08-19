//Given a string s, find the length of the longest substring without repeating 
//characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
// 
//
// Example 2: 
//
// 
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
// 
//
// Example 3: 
//
// 
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a 
//substring.
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s consists of English letters, digits, symbols and spaces. 
// 
//
// Related Topics Hash Table String Sliding Window 👍 34604 👎 1536


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0;
        vector<int> table(128, -1);
        for (int right = 0; right < s.length(); ++right) {
            if (table[s[right]] >= left) {
                left = table[s[right]] + 1;
            }
            table[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
