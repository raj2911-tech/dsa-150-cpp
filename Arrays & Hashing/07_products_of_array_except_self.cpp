/*
Problem: Product of Array Except Self  
Link: https://leetcode.com/problems/product-of-array-except-self/  
Category: Arrays / Prefix & Suffix Product  
Difficulty: Medium  

Approach:  
- Create two auxiliary arrays:  
  1. `before[i]`: Product of all elements to the **left** of index `i`  
  2. `after[i]`: Product of all elements to the **right** of index `i`  
- Final result at index `i` is the product of `before[i] * after[i]`, i.e., product of all elements except `nums[i]`.  
- This avoids using division and handles zeros correctly.

Steps:  
1. Initialize both `before` and `after` arrays with 1s.  
2. Fill `before[i]` by forward traversal using running product.  
3. Fill `after[i]` by backward traversal using running product.  
4. Multiply corresponding values of `before[i]` and `after[i]` to get the final result.

Time Complexity:  
- O(n) — one pass for each of the three loops

Space Complexity:  
- O(n) — for the `before`, `after`, and `res` arrays  
(Optimal version exists with O(1) extra space excluding output array)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> before(n, 1);
        vector<int> after(n, 1);

        for (int i = 1; i < n; i++) {
            before[i] = nums[i - 1] * before[i - 1];  // Prefix product
        }

        for (int i = n - 2; i >= 0; i--) {
            after[i] = nums[i + 1] * after[i + 1];    // Suffix product
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = before[i] * after[i];            // Final product excluding self
        }

        return res;
    }
};
