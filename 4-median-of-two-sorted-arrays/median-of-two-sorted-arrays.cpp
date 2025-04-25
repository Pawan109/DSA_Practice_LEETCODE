class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
/*First, I started with a brute force merge approach (O(n + m)).

Then, I noticed both arrays are sorted, and we can binary search for the correct partition.

I assumed one array is smaller and binary searched on its partition index.-> BS on smaller array only. 

I calculated the corresponding partition in the second array.

The goal was to ensure left parts are all ≤ right parts. //left part (mix of both arrays) //right part (mix of both arrays)

I used edge-safe values (INT_MIN, INT_MAX) for boundary cases.

This leads to a final solution in O(log(min(m, n))) time and O(1) space.*/

        //nums1 is a //nums2 is b // we are assuming a is smaller array 
        int n= nums1.size();
        int m = nums2.size();
        if(n>m){// for this question we are assuming nums1 is the smaller array 
            return findMedianSortedArrays(nums2,nums1);// and if its not, we swapped 
        }
        int s=0;
        int e=n;// e=n and not n-1 //***** because of the edge case where aleft = n (see dry run)
        int total_len= n+m;
        /*Smart Assumption
"To simplify, we assume nums1 is the smaller array. This lets us binary search over nums1’s indices only, reducing our search space to log(min(m, n))."*/

/*“We partition both arrays such that the total left part has exactly half of the total elements. We then ensure:

max element on the left ≤ min element on the right (from both arrays).”*/

/* If nums1[aleft-1] ≤ nums2[bleft] AND nums2[bleft-1] ≤ nums1[aleft], we have the correct split!*/
/**/

        while(s<=e){
            int aleft =  s+(e-s)/2;// aleft matlb mid //upar wali array ka i.e num1
            int bleft = (total_len + 1)/2 - aleft; //we will pick 0 se mid in num1 and rest num2 se
              
        // 1 2 3 4   7                       // 1 2 3 3 4 4  5 7 9 10 11 12 
        //  3 4    5 9 10 11 12 

            //edge cases for indices
            int alm1=(aleft==0)?INT_MIN: nums1[aleft-1];
            int al =(aleft==n)?INT_MAX: nums1[aleft];
            int blm1 =(bleft==0)?INT_MIN: nums2[bleft-1];
            int bl =(bleft==m)? INT_MAX: nums2[bleft];
            
            //valid segregation
            if(alm1<=bl &&  blm1<=al){ // 2 conditions
                 double median = 0.0;
                if(total_len%2==0){
                    int lmax = max(alm1,blm1);
                    int rmin = min(al,bl);
                    median = (lmax+rmin)/2.0;
                }
                else{
                    int lmax = max(alm1,blm1);
                    median = lmax;
                }
                return median;
            }//not a valid seggreation means-> make use of the binary search 
            else if(alm1>bl){ //2nd condition failed
                //more elements should be picked from left part in neeche wali array (nums2 or b)
                e= aleft-1;
            }
            else if(blm1>al){//1st condition failed
                //more elements should be picked from left part in upar wali array (nums1 or a)
                s = aleft+1; 
            }
        }
        return 0;
    }
};