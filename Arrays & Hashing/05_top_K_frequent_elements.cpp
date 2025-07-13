/*
Problem: Top K Frequent Elements
Link: https://leetcode.com/problems/top-k-frequent-elements/
Category: Hashing / Heap / Sorting
Difficulty: Medium

Approach:
1. Count the frequency of each element using an unordered_map.
2. Store each (frequency, element) pair into a vector.
3. Sort the vector in descending order based on frequency.
4. Extract the top k elements from the sorted vector and return them.

This approach uses sorting instead of a heap or bucket sort for simplicity.

Time Complexity:
- O(n log n) —
    O(n) for frequency map construction +
    O(n log n) for sorting the frequency vector (n = number of unique elements)

Space Complexity:
- O(n) —
    for the frequency map and frequency vector

*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        vector<pair<int, int>> v;

        for (auto i : m)
        {
            v.push_back({i.second, i.first});
        }

        sort(v.rbegin(), v.rend());

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].second);
        }

        return res;
    }
};
