class Solution {
public:


    void helper(vector<int> & arr, int ind, vector<vector<int>> &ans){
        
        if(ind==arr.size()){
            ans.push_back(arr);
            return;
        }
        
        
        unordered_set<int> s;
        
        for(int i=ind; i<arr.size();i++){
            
           if(s.count(arr[i])) continue;  //if already there in set. 
            
           s.insert(arr[i]);
            
            swap(arr[i],arr[ind]);
            helper(arr,ind+1,ans);
            swap(arr[i],arr[ind]); //backtrack
        }
    }
  
    
  

    vector<vector<int>> permuteUnique(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end()); //so that duplicates are adjacent now 
        helper(arr,0,ans);
        return ans;
    }
};