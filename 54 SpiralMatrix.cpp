class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> spiral; spiral.reserve(m * n);

        int r = 0, c = 0, i;
        while(r < m && c < n) {
            for(i = c; i < n; ++i)
                spiral.push_back(matrix[r][i]);

            --n;

            for(i = r + 1; i < m; ++i)
                spiral.push_back(matrix[i][n]);

            --m;

            if(r >= m || c >= n)
                break;

            for(i = n - 1; i >= c; --i)
                spiral.push_back(matrix[m][i]);
                
            ++r;

            for(i = m - 1; i >= r; --i)
                spiral.push_back(matrix[i][c]);

            ++c;
        }

        return spiral;
    }
};