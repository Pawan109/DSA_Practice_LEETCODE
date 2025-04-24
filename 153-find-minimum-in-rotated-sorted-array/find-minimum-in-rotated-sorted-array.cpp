class Solution {
public:
    int findMin(vector<int>& A) {
        int s = 0;
        int n = A.size();
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            //smallest ele 
            if(A[mid]<=A[prev] && A[mid]<=A[next]){
                return A[mid];
                
            }
           //always check in this order, pehle mid se e check karo sorted hai ki nahi
           //kyuki rotated array isi order mein milega 
           //then check for s to mid 
            else if(A[mid]<=A[e]){ //mid se leke e tak sorted hai , and mid is not the smallest -> check in 0tomid-1
                e=mid-1;
            }
             else if (A[s]<=A[mid]) { //0 se leke mid tak sorted hai , and mid is not the smallest ele -> check in mid+1toe
                s = mid+1;
            }
        }
        return -1;
    }
};