class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        string s;
        for(const auto& str : strs) {
            s = str; sort(s.begin(), s.end());
            anagrams[s].push_back(str);
        }

        vector<vector<string>> groups; groups.reserve(anagrams.size());

        for(const auto& anagram : anagrams) 
            groups.push_back(anagram.second);

        return groups;
    }
};