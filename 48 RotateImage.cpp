class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), rows = n / 2;

        int rotations, prev, next;
        for(int i = 0; i < rows; ++i) {
            rotations = n - i - i - 1;

            for(int j = 0; j < rotations; ++j) {
                next = matrix[i][i + j];

                prev = matrix[i + j][n - i - 1];
                matrix[i + j][n - i - 1] = next;
                next = prev;

                prev = matrix[n - i - 1][n - i - 1 - j];
                matrix[n - i - 1][n - i - 1 - j] = next;
                next = prev;

                prev = matrix[n - i - 1 - j][i];
                matrix[n - i - 1 - j][i] = next;
                next = prev;

                matrix[i][i + j] = next;
            }
        }
    }
};