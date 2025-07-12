/*

Problem: Group Anagrams  
Link: https://leetcode.com/problems/group-anagrams/  
Category: Hashing / Strings  
Difficulty: Medium  

Approach:  
For each word in the input list, sort its characters to form a canonical version (anagram signature).  
Use this sorted string as a key in an unordered_map and group all original words with the same sorted key.  
Finally, extract the grouped anagrams from the map into a result vector.  

Time Complexity: O(n * k log k) —  
    where n = number of strings, k = maximum length of a string  
    because sorting each string of length k takes O(k log k)  
Space Complexity: O(n * k) — for storing grouped anagrams in the hash map

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());  
            m[temp].push_back(strs[i]);      
        }

        vector<vector<string>> result;

        for (auto it : m) {
            result.push_back(it.second);
        }

        return result;
    }
};

