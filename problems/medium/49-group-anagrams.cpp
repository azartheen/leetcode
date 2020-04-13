/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string, vector<string>> m;
        for(string s: strs){
            string tmp=s;
            sort(s.begin(), s.end());
            m[s].push_back(tmp);
        }
        vector<vector<string>> ans;
        for(auto k: m) ans.push_back(k.second);
        return ans;
    }
};