class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0;
        
        for(int i = 0;i<points.size();i++)
        {
            map<pair<int,int>,int> mp;
            int same = 1;
            
            int x1 = points[i][0], y1 = points[i][1];
            
            for(int j = i+1;j<points.size();j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                
                int dx = x2 - x1;
                int dy = y2 - y1;
                
                if(dx==0 && dy==0){
                    same++;
                    continue;
                }
                
                // parallel to x
                if(dy==0){
                    // not dependent on dx now , so dx -1
                    mp[{-1,0}]++;
                    continue;
                }
                
                // parallel to y
                if(dx==0){
                    // not dependent on dy , so dy = -1
                    mp[{0,-1}]++;
                    continue;
                }
                
                int g = __gcd(abs(dx),abs(dy));
                dx /= g;
                dy /= g;
                
                if((long long)dx*dy > 0)
                {
                    mp[{abs(dx),abs(dy)}]++;
                }
                else{
                    mp[{-abs(dx),abs(dy)}]++;
                }
                
            }

            for(auto ele : mp)
            {
                ans = max(ans,ele.second + same);
            }
            
            if(mp.empty())
                ans = max(ans,same); // when mp is empty and we only have same
            
        }
        
        return ans;
    }
};
