class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxE = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int i=0,j=0;

        int countMaxE = 0;
        long long ans = 0;

        while(j<n){

            if(nums[j] == maxE) countMaxE++;

            while(countMaxE >=k ){
                ans += n-j;

                if(nums[i]==maxE) countMaxE--;
                i++;

            }
        
        j++;
        }
    return ans;
    }
};