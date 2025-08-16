class Solution {
public:
    
    static bool comp(int a, int b){
        string n1 = to_string(a)+to_string(b);
        string n2 = to_string(b)+to_string(a);
        if(n1>n2) return true;
        else return false;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans = "";

        sort(nums.begin(),nums.end(),comp);
        
        //base case  if nums ={0,0,0..} i.e sb zero hai -> toh output should be 0 and not 0000..
      if(nums[0]==0) return "0";
        
        for(auto x:nums) ans+=to_string(x);
        
        return ans;
    }
};