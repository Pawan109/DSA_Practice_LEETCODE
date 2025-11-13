class Solution {
public:

    int m,n, N;
    
    bool solve( int i , int j, int k,string &s1, string &s2, string &s3 ,
    vector<vector<vector<int>>> &dp){
        
        if(i==m && j== n && k==N) return true;
        
        if(k>=N) return false;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        bool result = false; 
        
        if(i<m && s1[i]==s3[k]) result = solve(i+1, j, k+1, s1,s2,s3,dp);
        
        if(result == true) return true; 
        
        
        if(j<n && s2[j]==s3[k]) result = solve(i, j+1, k+1, s1,s2,s3,dp);
        
        return dp[i][j][k] = result;
    }
    
  
    bool isInterleave(string s1, string s2, string s3) {
        // code here
        m = s1.size();
        n = s2.size();
        N= s3.size();
       
        vector<vector<vector<int>>> dp ( m+1, vector<vector<int>>(n+1,vector<int>(N+1,-1)));
        
        return solve(0,0,0,s1,s2,s3,dp);
    }

};