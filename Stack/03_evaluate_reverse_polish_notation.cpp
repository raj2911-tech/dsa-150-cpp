/*
Problem: Evaluate Reverse Polish Notation  
Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/  
Category: Stack / Math  
Difficulty: Medium  

Approach (Using Stack):  
- Use a stack to evaluate the expression from left to right.
- If the current token is a number, push it onto the stack.
- If it’s an operator (+, -, *, /):  
  - Pop the top two elements from the stack:  
    - The **second-popped** value is the **left operand**,  
    - The **first-popped** is the **right operand** (important for `-` and `/`)
  - Apply the operation and push the result back to the stack.
- At the end, the stack contains a single result — return it.

Why it works:  
- Reverse Polish Notation (RPN) or postfix notation eliminates the need for parentheses.
- The stack naturally keeps track of operands in the correct order of operations.

Time Complexity:  
- O(n) — one pass through the `tokens` array

Space Complexity:  
- O(n) — stack may hold up to `n`/2 numbers in worst case

Note:  
- `stoi()` is used to convert string tokens to integers

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for (int i = 0; i < tokens.size(); i++) {
            
            if (tokens[i] == "+") {
                int right = ans.top(); ans.pop();
                int left = ans.top(); ans.pop();
                ans.push(left + right);

            } else if (tokens[i] == "-") {
                int right = ans.top(); ans.pop();
                int left = ans.top(); ans.pop();
                ans.push(left - right);

            } else if (tokens[i] == "*") {
                int right = ans.top(); ans.pop();
                int left = ans.top(); ans.pop();
                ans.push(left * right);

            } else if (tokens[i] == "/") {
                int right = ans.top(); ans.pop();
                int left = ans.top(); ans.pop();
                ans.push(left / right);
                
            } else {
                ans.push(stoi(tokens[i]));
            }
        }
        return ans.top();
    }
};
