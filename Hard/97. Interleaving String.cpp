bool isInterleave_recur(string s1, string s2, string s3,int idx_s1, int idx_s2,int idx_s3,vector<vector<int>> &dp)
{
    if(idx_s3==s3.length() && idx_s2==s2.length() && idx_s1==s1.length()) return true;
    if(idx_s3==s3.length()) return false;

    if(dp[idx_s1][idx_s2] != -1) return dp[idx_s1][idx_s2];

    bool res1 = false;
    bool res2 = false;

    if(idx_s1 < s1.length() && s1[idx_s1]==s3[idx_s3])
    {
        res1 = isInterleave_recur(s1,s2,s3,idx_s1+1,idx_s2,idx_s3+1,dp);
    }

    if(idx_s2 < s2.length() && s2[idx_s2]==s3[idx_s3])
    {
        res2 = isInterleave_recur(s1,s2,s3,idx_s1,idx_s2+1,idx_s3+1,dp);
    }
    dp[idx_s1][idx_s2] = res1 || res2 ? 1 : 0;
    return res1 || res2;
}

bool isInterleave(string s1, string s2, string s3)
{
    vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    return isInterleave_recur(s1,s2,s3,0,0,0,dp);


}
