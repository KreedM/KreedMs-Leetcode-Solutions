class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), start = 0, maxLen = 1;

        vector<vector<bool>> ss_is_pal(len, vector<bool>(len));

        for(int i = 0; i < len; ++i)
            ss_is_pal[i][i] = true;
        
        for(int i = 0; i + 1 < len; ++i) {
            if(s[i] == s[i + 1]) {
                ss_is_pal[i][i + 1] = true;

                start = i, maxLen = 2;
            }
        }

        for(int i = 2; i < len; ++i) {
            for(int j = 0; j + i < len; ++j) {
                if(s[j] == s[j + i] && ss_is_pal[j + 1][j + i - 1]) {
                    ss_is_pal[j][j + i] = true;

                    start = j, maxLen = i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};