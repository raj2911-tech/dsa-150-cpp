/*

Problem: Valid Anagram  
Link: https://leetcode.com/problems/valid-anagram/  
Category: Sorting / Hashing  
Difficulty: Easy  

Approach:  
Sort both input strings and compare them directly.  
If both sorted strings are equal, then the original strings are anagrams of each other.  

Time Complexity: O(n log n) — due to sorting  
Space Complexity: O(1) — ignoring input size, as no extra space proportional to input is used

*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};