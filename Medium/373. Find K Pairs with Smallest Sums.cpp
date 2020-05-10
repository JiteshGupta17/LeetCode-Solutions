class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size(),m = nums2.size();
        if(n==0 || m==0) return vector<vector<int>>();
        set<pair<int,int>> st;
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
           // as priority_queue therefor opposite
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        pq.push({0,0});
        vector<vector<int>> ans;
        
        while(k-- && !pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            
            int i = cur.first;
            int j = cur.second;
            
            ans.push_back({nums1[i],nums2[j]});
            
            if(i+1<n && st.count({i+1,j})==0){
                st.insert({i+1,j});
                pq.push({i+1,j});
            }
            
            if(j+1<m && st.count({i,j+1})==0){
                st.insert({i,j+1});
                pq.push({i,j+1});
            }
              
        }
        
        return ans;
    }
};
