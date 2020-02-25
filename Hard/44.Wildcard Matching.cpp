#include<bits/stdc++.h>
using namespace std;

bool isMatch_Recur(string s,string p,int i,int j)
{
    if(j==p.length()) return i==s.length();

    if(s[i]==p[j] || p[j]=='?') return isMatch_Recur(s,p,i+1,j+1);

    if(p[j]=='*')
    {
        return isMatch_Recur(s,p,i+1,j) || isMatch_Recur(s,p,i+1,j+1) || isMatch_Recur(s,p,i,j+1);
    }

    return false;
}

bool isMatch(string s,string p)
{
    int n = s.length();
    int m = p.length();

    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

    dp[n][m] = true;

    // This is because string s might end but there can be any numbers of stars at the end of pattern
    // but these end stars dont effect the answere as the can be null
    for(int j = m-1;j>=0;j--)
    {
        if(p[j]=='*')
        {
            dp[n][j] = true;
        }
        else break;
    }

    for(int i = n-1;i>=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {

            if(s[i]==p[j] || p[j]=='?') dp[i][j] = dp[i+1][j+1];
            else if(p[j]=='*') {
                dp[i][j] = dp[i+1][j] || dp[i+1][j+1] || dp[i][j+1];
            }
        }
    }

    // for(auto v : dp)
    // {
    //     for(auto ele : v) cout<<ele<<" ";
    //     cout<<endl;
    // }

    return dp[0][0];
}

int main()
{
    cout<<boolalpha<< isMatch_Recur("","*",0,0) <<endl;

    cout<<boolalpha<< isMatch("","*") <<endl;

}