class Solution {
public:
   
    
    int merge(vector<int>& nums,int s,int mid, int e){
        
        
        int j=mid+1;
        int count = 0;
        vector<int> temp;
        for(int i=s;i<=mid;i++){
            while(j<=e && nums[i]>2*(long)nums[j]) j++;
            
            count+= (j-(mid+1));
        }
        
        int   a=s ,b=mid+1;
        while(a<=mid && b<=e){
            if(nums[a]<=nums[b]) temp.push_back(nums[a++]);
            else temp.push_back(nums[b++]);
        }
        while(a<=mid) temp.push_back(nums[a++]);
        while(b<=e) temp.push_back(nums[b++]);
        
         for (int p= s; p<= e; p++) {  
            nums[p] = temp[p-s];   //again taking back element in nums array after completing our goal of creating a temporary vector to store 
        }                       //sorted broken arrays and check inversions in them(nums[i]>2*nums[j])
        
        return count;
    }
    
    int mergeSort(vector<int>& nums,int s, int e ){
       if(s>=e) return 0;
        int mid = s+(e-s)/2;
        
        int count =mergeSort(nums,s,mid);
        count+= mergeSort(nums,mid+1,e);
        count+= merge(nums,s,mid,e);
        return count;
    }
    
     int reversePairs(vector<int>& nums) {
        
       
        int n=nums.size();
       
        return mergeSort(nums,0,n-1);
    
    }
};