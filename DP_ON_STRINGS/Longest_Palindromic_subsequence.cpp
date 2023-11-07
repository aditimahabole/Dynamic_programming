class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());// reverse second string
        // now apply Longest common subsequence
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
};
