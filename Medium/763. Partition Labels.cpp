class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> map(26,-1);
        
        for(int i = 0;i<S.size();i++)
        {
            map[S[i]-'a'] = i;
        }
        
        int prev = 0;
        int max_idx = -1;
        vector<int> ans;
        
        for(int i = 0;i<S.size();i++)
        {
            
            int next_posi = map[S[i]-'a'];
            max_idx = max(max_idx,next_posi);
            
            if(i==max_idx)
            {
                ans.push_back(max_idx - prev+1);
                prev = i+1;
            }
        }
        
        return ans;
        
    }
};
