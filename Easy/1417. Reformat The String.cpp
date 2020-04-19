class Solution {
public:
    string reformat(string s) {
        string ans = "";
        int alphas = 0;
        int nums = 0;
        
        string a = "";
        string d = "";
        for(int i = 0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                nums++;
                d.push_back(s[i]);
            }
            else{
                alphas ++;
                a.push_back(s[i]);
            } 
        }
        
        if(abs(nums-alphas) > 1) return "";
        
        if(nums < alphas) swap(d,a);
        
        int i = 0,j = 0;
        while(i<d.length() || j <a.length())
        {
             
            ans.push_back(d[i]);
            i++;
            
            if(j < a.length())
            {
                ans.push_back(a[j]);
                j++;
            }
        }
        
        return ans;
        
        
    }
};
