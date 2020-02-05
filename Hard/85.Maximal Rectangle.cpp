class Solution {
    int HistogramArea(vector<int> arr) {

        stack<int> s;
        int maxArea = 0;
        arr.push_back(-1);

        for (int i = 0; i < arr.size(); i++)
        {
            if (s.empty()) s.push(i);
            else
            {
                int top = s.top();

                while (arr[i] < arr[top])
                {
                    s.pop();
                    if (s.empty())
                    {
                        int CurArea = arr[top] * i;
                        maxArea = max(maxArea, CurArea);
                        break;
                    }
                    else {
                        int CurArea = arr[top] * (i - s.top() - 1);
                        maxArea = max(maxArea, CurArea);
                    }
                    top = s.top();
                }

                s.push(i);
            }
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;

        int maxArea = 0;
        vector<int> cur(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    cur[j] = 0;
                }
                else {
                    cur[j] += 1;
                }
            }

            int curArea = HistogramArea(cur);
            maxArea = max(maxArea, curArea);
        }

        return maxArea;
    }

};