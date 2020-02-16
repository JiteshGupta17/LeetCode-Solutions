class Solution {
public:
    
    static bool compare(vector<int> &v1,vector<int> &v2)
    {
        if(v1[1] != v2[1]) return v1[1] < v2[1];
        
        return v1[0] < v2[0];
    }
    
    int maxEvents(vector<vector<int>>& events) {
        
        // Sort by end time and incase end time same then sort by start time
        sort(events.begin(),events.end(),compare);
        
        // Using set
        // set<int> avail_days;
        // for(int i = 1;i<=100000;i++) avail_days.insert(i);
        
        int ans = 0;
        
        // Using vector
        vector<bool> days(100001,true);
        
        for(auto event : events)
        {
            int s = event[0]; int e = event[1];
           
            // auto it = avail_days.lower_bound(s);
            // if(it != avail_days.end() && *it <= e)
            // {
            //     ans++;
            //     avail_days.erase(it);
            // }
            
            while(s <= e)
            {
                if(days[s])
                {
                    ans++;
                    days[s] = false;
                    break;
                }
                else s++;
            }

        }
        
        return ans;
    }
};
