/*
Problem: Two Sum II – Input Array Is Sorted  
Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/  
Category: Two Pointers / Binary Search  
Difficulty: Easy  

Approach:  
- Use two pointers `l` (left) and `r` (right) starting from the beginning and end of the sorted array.  
- Calculate the sum of `numbers[l] + numbers[r]`:  
  - If sum > target → move `r` to the left to reduce the sum  
  - If sum < target → move `l` to the right to increase the sum  
  - If sum == target → return the 1-based indices `{l + 1, r + 1}`

Why it works:  
- The array is sorted, so increasing or decreasing the pointer helps reach the target efficiently.

Time Complexity:  
- O(n) — each element is visited at most once

Space Complexity:  
- O(1) — no extra space used

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum > target) {
                r--;  // Reduce sum by moving right pointer left
            }
            else if (sum < target) {
                l++;  // Increase sum by moving left pointer right
            }
            else {
                return {l + 1, r + 1};  // Found the pair (1-based index)
            }
        }

        return {};  // Will not reach here per problem constraints
    }
};
