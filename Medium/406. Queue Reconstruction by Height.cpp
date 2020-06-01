class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        auto cmp  =[&](vector<int> v1,vector<int> v2)
        {
            if(v1[0] != v2[0]) return v1[0] > v2[0];
            return v1[1] < v2[1];
        };
        
        // Increasing order of height as we know greater than or equal to for each person
        
        sort(people.begin(),people.end(),cmp);
        
        vector<vector<int>> ans;
        for(auto & vec : people)
        {
            ans.insert(ans.begin() + vec[1],vec);
        }
        
        return ans;
    }
};
