class Solution {
public:
    int minInsertions(string s) {
        //first find the longest palindromic subsequence 
        // eg for mbadm it would be m a m 
        // now we have to put letters btw them so that it becomes palindrome
        // m b a d m so if i take b and place it after d
        // m b a d b m and take d and place it on left side 
        // m b d a d b m we got it
        // first find longest palindrome then 
        // return total_len- len of palindromic  string 
        int n = s.length();
        string s1 = s ;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s1[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return n - dp[n][n];
        
    }
};
