class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0;
        unordered_map<int,int> mymap;
        int prefix_sum = 0;

        for(int i=0;i< nums.size();i++){
            prefix_sum += nums[i];
            if(prefix_sum==k) ans++;

            if(mymap.find(prefix_sum-k)!=mymap.end()) ans+= mymap[prefix_sum-k];

            mymap[prefix_sum]++;
        }

        return ans;
    }
};