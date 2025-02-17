#define get_nth_char(s, n) (s[n - 1])

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<int> lcs(m + 1, 0), curr(m + 1);
        for(int i = 1; i <= n; ++i) {
            curr[0] = 0;

            for(int j = 1; j <= m; ++j) {
                if(get_nth_char(text1, i) == get_nth_char(text2, j))
                    curr[j] = lcs[j - 1] + 1;
                else
                    curr[j] = max(curr[j - 1], lcs[j]);
            }

            lcs = curr;
        }

        return lcs[m];
    }
};