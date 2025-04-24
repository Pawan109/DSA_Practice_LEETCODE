class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        //so we have to find the floor if element not found 
        int s = 0;
        int e = n-1;

        //int target = -1;
        int floor = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(nums[mid]==target) return mid; //we need the index 

            else if(nums[mid]<target){
               floor = mid;
               s=mid+1; 
            }
            else e=mid-1;
        }
        return  floor+1;
    }
};