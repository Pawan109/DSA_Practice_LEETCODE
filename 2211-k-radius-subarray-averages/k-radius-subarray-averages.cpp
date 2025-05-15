class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans(n,-1);

        if(k==0) return nums;

        if(n < 2*k+1) return ans;

        int s = 0;
        int e = 2*k;
        long long windowSum = 0;

        int i=k;
        for( int ii=s;ii<=e;ii++) windowSum += nums[ii];
        
        ans[i] =  windowSum/(2*k +1);
        i++;
        e++;

        while(e<n){

            windowSum -= nums[s];
            windowSum += nums[e];

            ans[i] = windowSum/(2*k +1);
            i++;

            s++;
            e++;
        }

        return ans;
    }
};