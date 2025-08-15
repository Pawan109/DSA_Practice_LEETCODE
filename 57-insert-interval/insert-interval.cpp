class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans; 
        
        int i=0;
        
        while(i< intervals.size()){
            if(intervals[i][1]< newInterval[0] ) // 1,2  and newIntervl is 3,4 -> no merge
                ans.push_back(intervals[i]);
                
            else if(intervals[i][0] > newInterval[1]) // 6,9  and newInterval is 1,4 --> th ab newInterval ko daalo ans mein aur remaining walo ko daalo ans mein bss  
                break;
                
            else{ //merge 
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
       
            i++;
       
        }
        
        ans.push_back(newInterval);
        
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};