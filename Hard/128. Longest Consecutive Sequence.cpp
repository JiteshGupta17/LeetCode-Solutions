class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> st;

        for (int ele : nums)
        {
            st.insert(ele);
        }

        int ans = 0;

        for (auto cur : st)
        {
            int cur_ans = 1;

            int prev = cur - 1;

            while (st.find(prev) != st.end())
            {
                st.erase(prev);
                cur_ans++;
                prev--;
            }

            int next = cur + 1;
            while (st.find(next) != st.end())
            {
                st.erase(next);
                cur_ans++;
                next ++;
            }

            ans = max(ans, cur_ans);

        }

        return ans;


    }
};