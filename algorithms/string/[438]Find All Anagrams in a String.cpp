//Given two strings s and p, return an array of all the start indices of p's 
//anagrams in s. You may return the answer in any order. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a 
//different word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
//
// 
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
// 
//
// Example 2: 
//
// 
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s and p consist of lowercase English letters. 
// 
//
// Related Topics Hash Table String Sliding Window 👍 11351 👎 316


#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> p_table(26);
        vector<int> window_table(26);

        if (p.length() > s.length()) return {};

        for (int i = 0; i < p.length(); ++i) {
            p_table[p[i] - 'a']++;
            window_table[s[i] - 'a']++;
        }

        if (p_table == window_table) ans.push_back(0);

        int left = 1;

        for (int right = left + p.length() - 1; right < s.length(); ++right, ++left) {
            window_table[s[right] - 'a'] ++;
            window_table[s[left-1] - 'a'] --;
            if (window_table == p_table) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
