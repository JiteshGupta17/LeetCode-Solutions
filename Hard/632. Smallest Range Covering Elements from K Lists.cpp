class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int n = nums.size();

        // Store the index on which we are for each row
        vector<int> indices(n);

        set<pair<int, int>> st; // first is element and second is row no

        for (int i = 0; i < n; i++)
        {
            st.insert({nums[i][0], i});
        }

        int start;
        int min_gap = INT_MAX;

        while (true)
        {
            auto low = *st.begin();
            auto high = *st.rbegin();

            int cur_gap = high.first - low.first;

            if (cur_gap < min_gap)
            {
                start = low.first;
                min_gap = cur_gap;
            }

            st.erase(st.begin());

            int cur_row = low.second;

            if (indices[cur_row] + 1 < nums[cur_row].size())
            {
                indices[cur_row]++;
                int idx = indices[cur_row];
                st.insert({nums[cur_row][idx], cur_row});
            }
            else break;

        }

        return {start, start + min_gap};

    }
};
