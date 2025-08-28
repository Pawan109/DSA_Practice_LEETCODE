class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
         int ans=0;
        int zeros=0;
        int start = 0;
        
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]==0) zeros++;
            
            while(zeros>k){
                if(arr[start]==0) zeros--;
                
                start++;
            }
            
            ans = max(ans, i-start+1);   
        
        }
        return ans ; 
    }
};