int numRescueBoats(vector<int>& people, int limit) {

    sort(people.begin(), people.end());

    int l = 0, r = people.size() - 1;

    int ans = 0;

    while (l <= r)
    {
        int cur = people[l] + people[r];
        
        if (cur <= limit)
        {
            l++; r--;
            ans ++;
        }
        else if (cur > limit)
        {
            r--;
            ans ++;
        }
    }

    return ans;

}
