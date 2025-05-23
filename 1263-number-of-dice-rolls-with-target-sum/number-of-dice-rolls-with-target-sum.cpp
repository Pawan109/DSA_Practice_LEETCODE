class Solution {
public:

    int dp[31][1001];
    int M = 1e9+7;

    int solve(int n , int k , int target){
         if(target<0) return 0;
        if(n==0 && target==0) return 1; 
        else if(n==0 && target!=0) return 0;

        if(dp[n][target]!=-1) return dp[n][target];

        int ways = 0;
        for(int i=1;i<=k;i++){

            ways += solve(n-1,k,target-i);
            ways %= M;
        }

        return dp[n][target]= ways;


    }



    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));

        return solve(n,k,target);
    }
};