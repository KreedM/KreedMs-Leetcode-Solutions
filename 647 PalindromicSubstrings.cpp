class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length(), count = 0;

        vector<vector<bool>> ss_is_pal(len, vector<bool>(len));

        count += len;
        for(int i = 0; i < len; ++i)
            ss_is_pal[i][i] = true;
        
        for(int i = 0; i + 1 < len; ++i) {
            if(s[i] == s[i + 1]) {
                ss_is_pal[i][i + 1] = true;
                ++count;
            }
        }

        for(int i = 2; i < len; ++i) {
            for(int j = 0; j + i < len; ++j) {
                if(s[j] == s[j + i] && ss_is_pal[j + 1][j + i - 1]) {
                    ss_is_pal[j][j + i] = true;
                    ++count;
                }
            }
        }

        return count;
    }
};