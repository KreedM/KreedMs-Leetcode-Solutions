class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(123, 0);
        for(const char& c : t)
            ++freq[c];

        int count = t.size(), start = 0, end = 0, minStart = 0, minLen = INT_MAX;

        while(end < s.size()) {
            if(--freq[s[end++]] >= 0)
                --count;

            while(count == 0) {
                if(++freq[s[start++]] == 1) {
                    if(end - start + 1 < minLen) {
                        minLen = end - start + 1;
                        minStart = start - 1;
                    }

                    ++count;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};