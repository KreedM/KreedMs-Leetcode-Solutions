class Solution {
public:
    int characterReplacement(string s, int k) {
        int sz = s.length();

        vector<int> count(26, 0);
        ++count[s[0] - 'A'];

        int l = 0, maxLen = 1, maxChars = 1;
        for(int r = 1; r < sz; ++r) {
            maxChars = max(maxChars, ++count[s[r] - 'A']);
            
            if(maxChars + k > maxLen)
                ++maxLen;
            else
                --count[s[l++] - 'A'];
        }

        return maxLen;
    }
};