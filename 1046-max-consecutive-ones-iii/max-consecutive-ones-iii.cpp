class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int ans=0;
        int zeros=0;
        for(int i=0, j=0;i<arr.size();i++){
            zeros += arr[i]==0;
            while(zeros>k) {
                zeros-=arr[j]==0;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans ; 
    }
};