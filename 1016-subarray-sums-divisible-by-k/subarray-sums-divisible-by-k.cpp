class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        int ans = 0;
        int sum = 0;
       // mymap[0] = 1;//for remainder = 0.

        for(int i=0;i<nums.size();i++){
            sum+= nums[i];

            int rem = sum%k;

            if(rem==0) ans++; //-> we have to do mymap[0] = 1, for this case. 
            if(rem<0) rem = rem+k;

            if(mymap.find(rem)!=mymap.end()) ans += mymap[rem];
             mymap[rem]++;

        }

        return ans;
    }
};