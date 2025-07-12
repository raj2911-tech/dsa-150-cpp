/*

Problem: Two Sum  
Link: https://leetcode.com/problems/two-sum/  
Category: Hashing  
Difficulty: Easy  

Approach:  
Use an unordered_map to store the elements as we iterate.  
For each element, check if (target - current_element) exists in the map.  
If it does, return the indices. Otherwise, store the current element and its index.  

Time Complexity: O(n) — one pass through the array  
Space Complexity: O(n) — for the unordered_map

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for(int i=0; i<nums.size(); i++){
            int first=nums[i];
            int sec=target-first;

            if(m.find(sec)!=m.end()){
                return {m[sec],i};
            }
            else{
                m[nums[i]]=i;
            }
            
        }
    }
};
