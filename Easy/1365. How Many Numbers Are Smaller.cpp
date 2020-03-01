// Beats 100% solutions in both time and space

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

    map<int, int> m;
    vector<int> v(101, 0);

    for (int ele : nums) m[ele]++;

    int prev = 0;
    for (auto ele : m)
    {
        v[ele.first] = prev;
        prev += ele.second;
    }

    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = v[nums[i]];
    }

    return ans;


}
