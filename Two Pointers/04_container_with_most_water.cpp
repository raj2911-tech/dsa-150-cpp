/*
Problem: Container With Most Water  
Link: https://leetcode.com/problems/container-with-most-water/  
Category: Two Pointers / Greedy  
Difficulty: Medium  

Approach:  
- Use two pointers: `l` (left) and `r` (right), starting from the ends of the array.  
- At each step, compute the area formed by `heights[l]` and `heights[r]`:
  - Width = `r - l`
  - Height = `min(heights[l], heights[r])`
  - Area = height × width
- Update `maxsize` if current area is greater.
- Move the pointer pointing to the **shorter** line inward to potentially find a taller line and maximize area.

Why it works:  
- A taller line may help increase area only if the width shrinks,  
  so we skip shorter lines since they are the limiting factor.

Time Complexity:  
- O(n) — each index is visited at most once

Space Complexity:  
- O(1) — constant space used

*/


class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l=0;
        int r=heights.size()-1;
        int maxsize=0;

        while(l<r){
            int h= min(heights[l], heights[r]);
            int w= r-l; 

            int size= h*w;
            maxsize=max(size,maxsize);
            
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
     
        return maxsize;
    }
};
