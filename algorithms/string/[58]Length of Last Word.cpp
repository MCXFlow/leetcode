//Given a string s consisting of words and spaces, return the length of the 
//last word in the string. 
//
// A word is a maximal substring consisting of non-space characters only. 
//
// 
// Example 1: 
//
// 
//Input: s = "Hello World"
//Output: 5
//Explanation: The last word is "World" with length 5.
// 
//
// Example 2: 
//
// 
//Input: s = "   fly me   to   the moon  "
//Output: 4
//Explanation: The last word is "moon" with length 4.
// 
//
// Example 3: 
//
// 
//Input: s = "luffy is still joyboy"
//Output: 6
//Explanation: The last word is "joyboy" with length 6.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of only English letters and spaces ' '. 
// There will be at least one word in s. 
// 
//
// Related Topics String 👍 3834 👎 191


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                int j = i;
                while (j >= 0 && s[j] != ' ') {
                    j--;
                }
                return i - j;
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
