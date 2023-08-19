//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
//of rows like this: (you may want to display this pattern in a fixed font for 
//better legibility) 
//
// 
//P   A   H   N
//A P L S I I G
//Y   I   R
// 
//
// And then read line by line: "PAHNAPLSIIGYIR" 
//
// Write the code that will take a string and make this conversion given a 
//number of rows: 
//
// 
//string convert(string s, int numRows);
// 
//
// 
// Example 1: 
//
// 
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
// 
//
// Example 2: 
//
// 
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
// 
//
// Example 3: 
//
// 
//Input: s = "A", numRows = 1
//Output: "A"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consists of English letters (lower-case and upper-case), ',' and '.'. 
// 1 <= numRows <= 1000 
// 
//
// Related Topics String 👍 6458 👎 12812


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string arr[numRows];
        int t = 0, f = 0;
        for (auto i : s) {
            if (!f && t == numRows) {
                f = 1;
                t-=2;
            } else if (f && t == -1) {
                f = 0;
                t+=2;

            }
            arr[t].push_back(i);

            t += f ? -1 : +1;
        }
        string ans;
        for (auto i : arr) {
            ans.append(i);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
