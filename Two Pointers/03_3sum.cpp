/*
Problem: 3Sum  
Link: https://leetcode.com/problems/3sum/  
Category: Two Pointers / Sorting  
Difficulty: Medium  

Approach:  
- First, sort the input array to allow two-pointer traversal and easy duplicate handling.  
- For each index `i`, fix `nums[i]` and look for two other numbers such that their sum is `-nums[i]` (i.e., total sum = 0).  
- Use two pointers (`l` and `r`) starting from `i+1` and end of the array:  
  - If the sum is less than target → move `l` forward  
  - If greater → move `r` backward  
  - If equal → store the triplet and skip duplicates from both ends  
- Skip duplicate values for `nums[i]` to avoid repeated triplets.

Time Complexity:  
- O(n²) —  
  Outer loop runs O(n) times and inner loop (two-pointer) takes O(n) in worst case

Space Complexity:  
- O(1) —  
  Ignoring the output vector, no extra space is used

*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){

           if(i > 0 && nums[i] == nums[i - 1]) continue;


            int target= -nums[i];
            int l=i+1;
            int r=nums.size()-1;

            while(l<r){
                

                if(nums[l]+nums[r]==target){
                    result.push_back({nums[l],nums[r],nums[i]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]<target){
                    l++;
                }
                else if(nums[l]+nums[r]>target){
                    r--;
                }
            }

        }
        return result;
    }
};
