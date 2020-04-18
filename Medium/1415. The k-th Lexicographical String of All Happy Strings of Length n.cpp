class Solution {
public:
    vector<char> chs = {'a','b','c'};
    set<string> set;
    
    void construct(string ans,int i,int n)
    {
        if(i==n){
            set.insert(ans); return ;
        }
        
        for(char ch : chs)
        {
            if(ans[i-1]!=ch)
            {
                construct(ans + ch,i+1,n);
            }
        }
    }
    string getHappyString(int n, int k) {
        set.clear();
        construct("a",1,n);
        construct("b",1,n);
        construct("c",1,n);
        
        if(set.size() < k) return "";
        
        auto it = set.begin();
        for(int i = 1;i<k;i++)
        {
            it++;
        }
        
        return *it;
    }
};
