class Solution {
public:

    // https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
    // Time Complexity = O(n^3)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Calculating prefix sum along each row
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Now the problem becomes similiar to -
        // https://leetcode.com/problems/subarray-sum-equals-k/description/

        unordered_map<int, int> map;
        int ans = 0;

        // Assuming the matrix btw col1 and col2 inclusive into a single linear array

        for (int col1 = 0; col1 < m; col1++)
        {
            for (int col2 = col1; col2 < m; col2++ )
            {
                map.clear();
                map[0] = 1;
                int cumulative_sum = 0;

                for (int i  = 0; i < n; i++)
                {
                    int cur_ele = matrix[i][col2] - (col1 > 0 ? matrix[i][col1 - 1] : 0);
                    cumulative_sum += cur_ele;

                    if (map.find(cumulative_sum - target) != map.end())
                    {
                        ans += map[cumulative_sum - target];
                    }

                    map[cumulative_sum]++;
                }
            }
        }

        return ans;

    }
};
