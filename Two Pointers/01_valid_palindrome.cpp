/*
Problem: Valid Palindrome  
Link: https://leetcode.com/problems/valid-palindrome/  
Category: Two Pointers / String  
Difficulty: Easy  

Approach:  
- Use two pointers: `l` (left) and `r` (right) starting from the beginning and end of the string.  
- Skip all non-alphanumeric characters using `isalnum()`.  
- Compare characters after converting both to lowercase using `tolower()`.  
  - If mismatch found → return false.  
  - Else → move both pointers inward.  
- If loop completes without mismatches, the string is a valid palindrome.

Time Complexity:  
- O(n) — where n is the length of the string  
  Each character is visited at most once

Space Complexity:  
- O(1) — no extra space used (in-place two-pointer check)

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;  // Skip non-alphanumeric characters
            }
            while (l < r && !isalnum(s[r])) {
                r--;  // Skip non-alphanumeric characters
            }

            // Compare lowercase versions of characters
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;  // No mismatches found
    }
};
