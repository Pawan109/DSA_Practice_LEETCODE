class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0, j=0;
        int sum = 0;
        int minLen = nums.size()+1;

        for(int j=0;j<nums.size();j++){
            sum+= nums[j];

            while(sum>=target){
                minLen = min(minLen,j-i+1);
                sum -= nums[i];
                i++;
            }
        }
    return minLen==nums.size()+1 ? 0 : minLen;
    }
};