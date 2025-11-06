class Solution {
public:

    int findNext_BinarySearch(int ind, vector<vector<int>> &jobs){
        int s= ind+1;
        int e = jobs.size()-1;
        int ans = jobs.size();
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(jobs[mid][0] >= jobs[ind][1]){ //nonoverlapping milgaya 
                ans = mid;
                e = mid-1;
            }
            
            else s= mid+1;
        }
        
        return ans;
    }
  
    int helper(int ind, vector<vector<int>> &jobs, vector<int>&dp){
        
        if(ind >= jobs.size()) return 0;
        
        if (dp[ind] != -1) return dp[ind];
        
        // not_take the current job
        int not_take = helper(ind + 1, jobs, dp);

        //before taking the current job, lets find the ind of the next non-ovrlapping job
        int nextIndex = findNext_BinarySearch(ind,jobs);
         
         //take the current job
        int take = jobs[ind][2] + helper(nextIndex, jobs, dp);

         return dp[ind] = max(take, not_take);
        
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs (n, vector<int>(3, 0)); //{s, e, p}
        
        for(int i = 0; i<n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end());
        
        vector<int> dp(n+1,-1);
        return helper(0,jobs, dp);
        
    }
};