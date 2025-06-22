class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int n = arr.size();
        //now question has been boiled down to print Largest divisible subsequence 
        vector<int> dp(n,1);
        vector<int> hash(n,1);

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev =0;prev<i;prev++){
                //if(arr[i]>arr[prev] && dp[i]>(1+dp[prev])){ -->arr[i]>arr[prev] ye toh hoga hi, as we have sorted it 
                if(arr[i]%arr[prev]==0  && (1+dp[prev] >dp[i])){
                    dp[i] = 1+ dp[prev];
                    hash[i] = prev;
                }
            }
        }

        int len_LIS =-1;
        int lastInd =-1;
        for(int i=0;i<n;i++){
            if(dp[i] > len_LIS){
                len_LIS = dp[i];
                lastInd =i;
            }
        }


        vector<int> temp;
        temp.push_back(arr[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd = hash[lastInd];
            temp.push_back(arr[lastInd]);
        }

        reverse(temp.begin(),temp.end());
        return temp;

    }
};