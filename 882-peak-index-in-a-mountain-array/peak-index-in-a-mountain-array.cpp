class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //kuch nahi karna hai=> bss peak element nikaalna hai
        int n = arr.size();

        if(n==1) return 0; // no peak ele -> edge case 
        int s = 0;
        int e = n-1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(mid==0){ //edge case
                if(arr[mid]>arr[mid+1]) return mid;
                else s = mid+1;

            }
            else if(mid==n-1){ //another edge case 
                if(arr[mid]>arr[mid-1]) return mid;
                else e = mid-1;
            }

            else{
                if(arr[mid]> arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
                else if(arr[mid]<arr[mid+1]) s= mid+1; //mid+1 hi na hoga probable peak -> uski taraf jaenge
                else e = mid-1;
            }

        }
        return -1;
    }
};