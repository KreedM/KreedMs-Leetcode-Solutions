class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int knapsack[m + 1][n + 1];
        memset(knapsack, 0, sizeof(int) * (m + 1) * (n + 1));

        int numZeroes, numOnes;
        for(const string& str : strs) {
            numZeroes = count(str.begin(), str.end(), '0'); numOnes = str.length() - numZeroes;

            for(int i = m; i >= numZeroes; --i) {
                for(int j = n; j >= numOnes; --j)
                    knapsack[i][j] = max(knapsack[i][j], knapsack[i - numZeroes][j - numOnes] + 1);
            }
        }

        return knapsack[m][n];
    }
};