class Solution {

     int M = 1_000_000_007;
    //private int[][] dp = new int[32][1002];

    public int solve(int n , int k , int target,int[][] dp ){
        if(target<0) return 0;
        if(n==0 && target==0) return 1; 
        if(n==0 && target!=0) return 0;

        if(dp[n][target]!=-1) return dp[n][target];

        int ways = 0;
        for(int i=1;i<=k;i++){
            ways += solve(n-1,k,target-i,dp);

            ways = ways%M;
        }
    return dp[n][target] = ways;
    }


    public int numRollsToTarget(int n, int k, int target) {
        int[][] dp = new int[n+1][target+1];

        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }

        return solve(n,k, target,dp);
    }
}