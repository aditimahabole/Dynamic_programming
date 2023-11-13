class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n1 = str1.length();
	    int n2 = str2.length();
	    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
	    // finding common subsequence in both the strings
	    for(int i=1;i<=n1;i++)
	    {
	        for(int j=1;j<=n2;j++)
	        {
	            if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
	            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    int common_str_len = dp[n1][n2];
	    int deletion_from_str1 = n1 - common_str_len ;
	    int insertion_from_str2 = n2 - common_str_len ;
	    return deletion_from_str1+insertion_from_str2;
	    
	} 
};
