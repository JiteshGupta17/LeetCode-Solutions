class Solution {
public:

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int n  = matrix.size();
        int m  = matrix[0].size();

        // Calculating prefix Sum along each row
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Assuming the matrix between col_1 and col_2 inclusive as a single array

        int ans = INT_MIN;
        set<int> set;

        for (int col_1 = 0; col_1 < m; col_1++)
        {
            for (int col_2 = col_1 ; col_2 < m; col_2 ++)
            {
                set.clear();
                set.insert(0);
                int cum_sum = 0;

                for (int  i = 0; i < n; i++)
                {
                    int ele = matrix[i][col_2] - (col_1 > 0 ? matrix[i][col_1 - 1] : 0);
                    cum_sum += ele;

                    auto it = set.lower_bound(cum_sum - k);

                    /*
                    Mathematical proof -
                    let *it will point to x (which is also a prefix_sum) such that according to lower_bound
                    1) x >= cum_sum - k
                    2) k >= cum_sum - x
                    */

                    if (it != set.end()) {
                        ans = max(ans, cum_sum - *it);
                    }

                    set.insert(cum_sum);
                }

            }
        }

        return ans;
    }
};
