class Solution {
public:

    int isPalindrome(string &s, int i, int j,  vector<vector<int>> &dp){
      if(i>=j) return dp[i][j]=true; // means we got a palindorme from s,i,j
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s[i]==s[j]){
          //check for i+1 , j-1 now -> jisse pata chalega if its a palindrome or not
          //if palindrome hai -> means s,i,j is palindrome -> dp[i][j]=1
          
       return dp[i][j] = isPalindrome(s,i+1,j-1,dp); // recursion se palindrom mila toh dp[][] mein 1, else 0
       // if(dp[i][j]) return 1; // ek count milgaya   
      }
      
     return dp[i][j]=false;
  }


    int countSubstrings(string s) {
        int n=s.size();
          vector<vector<int>> dp(n,vector<int>(n,-1));
          
          int count=0;
          for(int i=0;i<n;i++){
              for(int j=i;j<n;j++){  
                  if(isPalindrome(s,i,j,dp)==1) count++;
              }
          }
          
          return count;
    }
};