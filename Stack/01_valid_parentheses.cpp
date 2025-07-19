/*
Problem: Valid Parentheses  
Link: https://leetcode.com/problems/valid-parentheses/  
Category: Stack / Strings  
Difficulty: Easy  

Approach:  
- Use a stack to keep track of opening brackets: '(', '[', '{'  
- Traverse the string:
  - If current character is an **opening bracket**, push it onto the stack.
  - If it's a **closing bracket**, check:
    - If the stack is empty → return false (no matching open bracket)
    - If the top of the stack is the matching opening bracket → pop it
    - Else → return false (mismatched pair)
- After the loop, if the stack is **not empty**, some opening brackets are unmatched → return false

Why it works:  
- Stack ensures **Last-In-First-Out** (LIFO) order,
  which is perfect for matching nested/paired structures like parentheses.

Time Complexity:  
- O(n) — we iterate through the string once  

Space Complexity:  
- O(n) — in worst case, we might store all characters in the stack  

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            // If current char is an opening bracket, push to stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } 
            // If it's a closing bracket
            else {
                // If there's no matching opening bracket
                if (stack.empty()) return false;

                // If it matches the top of the stack, pop it
                if (
                    (s[i] == ')' && stack.top() == '(') ||
                    (s[i] == '}' && stack.top() == '{') ||
                    (s[i] == ']' && stack.top() == '[')
                ) {
                    stack.pop();
                } 
                // Mismatch found
                else {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets matched
        return stack.empty();
    }
};
