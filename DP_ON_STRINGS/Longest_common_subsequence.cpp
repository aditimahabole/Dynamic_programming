
class Solution {
public:
    int solve(string text1, string text2, int i1, int i2,vector<vector<int>>&dp)
    {
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(text1[i1]==text2[i2])
        {
            return dp[i1][i2] = 1+solve(text1,text2,i1-1,i2-1,dp);
        }
        int move_i1 = solve(text1,text2,i1-1,i2,dp);
        int move_i2 = solve(text1,text2,i1,i2-1,dp);
        return dp[i1][i2] = 0+ max(move_i1,move_i2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
      //---memoization---
        // vector<vector<int>>dp(n1,vector<int>(n2,-1));
        // return solve(text1,text2,n1-1,n2-1,dp);
      //-- tabulation--
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1]; // matched
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]); // not matched
            }
        }
        return dp[n1][n2];
    }
};
