class Solution {
public:

    int countLessEqual(int x, int m, int n){
        int count  = 0;

        for(int i=1;i<=m;i++){
            count += min(x/i,n);
        }

        return count;

    }

    int findKthNumber(int m, int n, int k) {
        
        int s =1, e = m*n;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(countLessEqual(mid,m,n) <k) s = mid+1;
            else e=mid-1;
        }


        return s;
    }
};