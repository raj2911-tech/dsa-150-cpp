/* 

Problem: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
Category: Hashing
Difficulty: Easy
Approach: Use an unordered_set to track seen elements while iterating.
Time Complexity: O(n)
Space Complexity: O(n)

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};


