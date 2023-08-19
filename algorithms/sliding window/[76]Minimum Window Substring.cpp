//Given two strings s and t of lengths m and n respectively, return the minimum 
//window substring of s such that every character in t (including duplicates) is 
//included in the window. If there is no such substring, return the empty string 
//"". 
//
// The testcases will be generated such that the answer is unique. 
//
// 
// Example 1: 
//
// 
//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' 
//from string t.
// 
//
// Example 2: 
//
// 
//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.
// 
//
// Example 3: 
//
// 
//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.
// 
//
// 
// Constraints: 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 10⁵ 
// s and t consist of uppercase and lowercase English letters. 
// 
//
// 
// Follow up: Could you find an algorithm that runs in O(m + n) time? 
//
// Related Topics Hash Table String Sliding Window 👍 15182 👎 640


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if(s == t) return s;
        int left = 0, ans_len = INT_MAX, ans_l = 0;
        vector<int> s_table(128, 0), t_table(128, 0);
        for (auto i : t) t_table[i]++;
        string ans;
        list<char> not_complete;
        for (int i = 0; i < 128; ++i) {
            if (t_table[i] > 0) not_complete.push_back(i);
        }
        for (int right = left; right < s.length(); ++right) {
            s_table[s[right]]++;
            if (t_table[s[right]] && s_table[s[right]] >= t_table[s[right]]) {
                not_complete.remove(s[right]);
            }
            while (not_complete.empty()) {
                if (right - left + 1 < ans_len) {
                    ans_len = right - left + 1;
                    ans_l = left;
                }
                s_table[s[left++]] --;
                if (t_table[s[left - 1]] && s_table[s[left - 1]] < t_table[s[left - 1]]) {
                    not_complete.push_back(s[left - 1]);
                }
            }
        }
        ans = s.substr(ans_l, ans_len == INT_MAX ? 0 : ans_len);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
