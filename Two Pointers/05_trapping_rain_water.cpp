/*
Problem: Trapping Rain Water  
Link: https://leetcode.com/problems/trapping-rain-water/  
Category: Arrays / Two Pointers / Prefix-Suffix  
Difficulty: Hard  

Approach (Prefix Maximums):  
- For every element in the array, the water trapped above it depends on the  
  **minimum of the maximum height to its left and right** minus its own height.  
- So, we precompute two arrays:  
  - `left[i]`  = max height from start to index i (inclusive)  
  - `right[i]` = max height from end to index i (inclusive)  
- Then for each index (except the first and last),  
  the water it can trap is: `min(left[i], right[i]) - height[i]`  
- Sum up all such values to get the total trapped water.

Why it works:  
- The minimum of the max heights on both sides forms the "ceiling" for trapped water.  
- Subtracting the current height gives how much water can sit on top.

Time Complexity:  
- O(n) — One pass to build `left`, one pass for `right`, one pass to compute result  

Space Complexity:  
- O(n) — Extra space for `left` and `right` arrays  

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int>right(n);
        int lmax=height[0];
        int rmax=height[n-1];

        for(int i=1; i<n; i++){
            lmax=max(lmax, height[i]);
            left[i]=lmax;
        }

         for(int i=n-1; i>-1; i--){
            rmax=max(rmax, height[i]);
            right[i]=rmax;
        }

        int count=0;
        for(int i=1; i<n-1; i++){
            count+= min(left[i], right[i])-height[i];
        }
        
        return count;
    }
};
