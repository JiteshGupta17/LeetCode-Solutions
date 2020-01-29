class Solution {
public:

    bool bs(vector<vector<int>>& matrix, int i, int x)
    {
        int l = 0, r = matrix[0].size() - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (matrix[i][m] == x) return true;

            if (matrix[i][m] < x)
                l = m + 1;
            else r = m - 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int x) {

        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;

        // bool f = false;
        for (int i = 0; i < n; i++)
        {
            if (x >= matrix[i][0] && x <= matrix[i][m - 1])
            {
                return bs(matrix, i, x);
            }
        }

        return false;
    }
};