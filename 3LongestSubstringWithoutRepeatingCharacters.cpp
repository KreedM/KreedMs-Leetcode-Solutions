class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.length(), count = 0, start = 0;

        unordered_map<char, int> index; index.reserve(sz);

        for(int i = 0; i < sz; ++i) {
            if(index.find(s[i]) != index.end() && index.at(s[i]) >= start) {
                count = max(count, i - start);
                start = index[s[i]] + 1;
            }

            index[s[i]] = i;
        }

        return max(count, sz - start);
    }
};