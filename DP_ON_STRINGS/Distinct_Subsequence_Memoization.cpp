class Solution {
public:

    int solve(string s, string t,int i,int j, vector<vector<int>>&dp)
    {
        if(j<0) return 1; // means we found s2 in s1
        if(i<0) return 0; // means s1 is not there so no s2 subseq poss
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == t[j])
        {
            int interested = solve(s,t,i-1,j-1,dp);
            int not_interested = solve(s,t,i-1,j,dp); // not interested to take charater in s1 we want to take another character 
            return dp[i][j] = interested + not_interested;
        }
        // if matching does not ocur just move s1 pointer
        return dp[i][j] = solve(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};
