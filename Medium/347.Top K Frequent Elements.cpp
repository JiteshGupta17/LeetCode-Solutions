vector<int> topKFrequent(vector<int>& nums, int k) {

    unordered_map <int, int> m;

    for (int ele : nums)
    {
        m[ele] ++;
    }

    priority_queue <pair<int, int>> pq;
    vector<int> ans;


    // Method 1
    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     pq.push({it->second, it->first});
    // }

    // for (int i = 0; i < k; i++)
    // {
    //     int cur = pq.top().second;
    //     ans.push_back(cur);
    //     pq.pop();
    // }

    // Method 2
    for (auto it = m.begin(); it != m.end(); it++)
    {
        pq.push({it->second, it->first});

        if (pq.size() > (int)m.size() - k) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }

    return ans;

}