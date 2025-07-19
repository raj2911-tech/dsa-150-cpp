/*
Problem: Min Stack  
Link: https://leetcode.com/problems/min-stack/  
Category: Stack / Design  
Difficulty: Medium  

Approach (Two Stacks):  
- Use two stacks:  
  1. `s`    → to store all values (normal stack)  
  2. `mins` → to keep track of the minimum value at each state  
- While pushing a value:
  - Always push it to `s`
  - Only push to `mins` if it's **smaller than or equal to** the current top of `mins`  
- While popping:
  - If the value popped from `s` is equal to the top of `mins`, pop from `mins` as well
- This ensures that `mins.top()` always gives the **minimum so far**

Why it works:  
- The `mins` stack keeps a history of minimums that are still "active" in the main stack.  
- Whenever a minimum is removed from the main stack, we remove it from the `mins` stack too.

Time Complexity:  
- `push`, `pop`, `top`, `getMin`: **O(1)** — all operations are constant time  

Space Complexity:  
- O(n) — due to using two stacks

*/
class MinStack {
public:
    stack<int>s;
    stack<int>mins;
    MinStack() {
        s={};
        mins={};
        
    }
    
    void push(int val) {
        s.push(val);
        if(mins.empty()) {
            mins.push(val);
        }
        else{
            if(val<=mins.top()){
                mins.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top()==mins.top()){
            mins.pop();
        }
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
