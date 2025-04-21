class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = n*(n+1)/2;


        int ele_sum = 0;
        for(int i=0;i<n;i++){
            ele_sum += nums[i];
        }
    
    return sum-ele_sum;
    }

};