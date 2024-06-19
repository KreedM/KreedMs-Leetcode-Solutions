class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();

        vector<vector<bool>> ss_is_pal(len, vector<bool>(len));

        for(int i = 0; i < len; ++i)
            ss_is_pal[i][i] = true;

        string pal = s.substr(0, 1);
        bool found = false;
        
        for(int i = 0; i + 1 < len; ++i) {
            if(s[i] == s[i + 1]) {
                ss_is_pal[i][i + 1] = true;

                if(!found) {
                    pal = s.substr(i, 2);
                    found = true;
                }
            }
        }

        for(int i = 2; i < len; ++i) {
            found = false;

            for(int j = 0; j + i < len; ++j) {
                if(s[j] == s[j + i] && ss_is_pal[j + 1][j + i - 1]) {
                    ss_is_pal[j][j + i] = true;

                    if(!found) {
                        pal = s.substr(j, i + 1);
                        found = true;
                    }
                }
            }
        }

        return pal;
    }
};