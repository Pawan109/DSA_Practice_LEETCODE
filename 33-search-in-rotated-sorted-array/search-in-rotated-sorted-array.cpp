class Solution {
public:
    int search(vector<int>& a, int target) {
        int s = 0;
        int e = a.size()-1;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(a[mid]==target){
                return mid;
            }
            
            //rotated sorted arr -> one half is always sorted. 
            //left half is sorted -> and target is in range 
            if(a[s]<=a[mid]){
                if(target>=a[s]&& target<=a[mid]){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }  
            else{ //left half isn't sorted -> right half sorted hoga -> target should be in range mid to e . 
                if(target>=a[mid]&& target<=a[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1; //if the target doesn't lie in the right half -> means it is there in the left unsorted half-> gothere
                }
            }
        }
        return -1;
    }
};