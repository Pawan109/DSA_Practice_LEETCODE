class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int mid){
        int sum=0;
        int count=1;//**** 1 se start hoga count , initiall array is in a single split . 
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum>mid){
                count++;
                sum = nums[i];// yahin se start again 
            }
            if(count>m) return false;
        }
        return true;
    }


    int splitArray(vector<int>& nums, int m) {
        // exactly same as allocate minimum no. of pages 
    //mujhe ye nahi pata, ki mujhe split kaha karna hai array. 
    //bss ye pata hai , ki kitne parts mein split karna hai . 
    //where to split the array from  -> mid tak ke elements lelo-> itna sum ek split mein hoga , >mid aaya , fir split karo .
    //if splitting in k subarrays is possible -> store ans -> store minimum of largest sum i.e max (sum of each subarray )and look for a even better answer. 

//search space -> 
//minimum 
//largest element in the array
//minimum se minimum kitne split karskte hai -> n split 
//if min maine kisi array ko one size ka split kardiya -> toh  sbse bada sum hoga -> max_element in the array 
//maximum.
// ab mujhe K mein split karna hai , toh maximum sum isse bada bhi hoskta hai ,
// maximum sum kitna aaega -> we didn't split -> total sum  i.e the largest possible sum will be our max sum 

//so our answer will lie in range from max_element to total sum .

        int s = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int e=sum;
        int ans=0;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(nums,m,mid)){
                ans=mid;
                e=mid-1;//modification, we need to minimize the largest 
            }
            else s=mid+1;
        }
        return ans;
    }
};