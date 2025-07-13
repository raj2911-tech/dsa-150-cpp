/*
Problem: Encode and Decode Strings  
Link: https://leetcode.com/problems/encode-and-decode-strings/  
Category: String / Design  
Difficulty: Medium  

Approach:  
**Encode**:  
- For each string in the input list, append its length, followed by a special delimiter (`#`), and then the string itself.  
- This avoids ambiguity in decoding, even if the string contains the delimiter character.

**Decode**:  
- Iterate through the encoded string to extract the length (up to the `#` delimiter),  
  then extract the exact number of characters following it as one original string.  
- Repeat until the entire string is processed.

This approach guarantees a one-to-one mapping between encoded and decoded strings.

Time Complexity:  
- Encode: O(n) — where n is the total number of characters in all strings  
- Decode: O(n) — same as above, since every character is processed once

Space Complexity:  
- O(n) — for storing the result string and decoded vector

*/

class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (string s : strs) {
            res += to_string(s.length()) + "#" + s;  
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
          
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};
