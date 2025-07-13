/*
Problem: Longest Consecutive Sequence  
Link: https://leetcode.com/problems/longest-consecutive-sequence/  
Category: Hashing / Arrays  
Difficulty: Medium  

Approach:  
- Insert all elements into an unordered_set for O(1) lookup.  
- For each number, check if it's the **start** of a sequence by ensuring (num - 1) is **not** in the set.  
  - If it is the start, count the length of the consecutive sequence starting from that number.  
- Keep track of the maximum sequence length.

Why it works:  
- Ensures each sequence is counted only once (at the start),  
  making it more efficient than sorting or re-checking chains repeatedly.

Time Complexity:  
- O(n) —  
  Each number is visited at most once, and set lookups are O(1) on average

Space Complexity:  
- O(n) — for storing elements in the unordered_set

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int l = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Check if current number is the start of a sequence
            if (s.find(nums[i] - 1) == s.end()) {
                int c = 1;
                int start = nums[i];

                // Count how long the consecutive sequence continues
                while (s.find(start + 1) != s.end()) {
                    c++;
                    start++;
                }

                l = max(c, l);
            }
        }

        return l;
    }
};
