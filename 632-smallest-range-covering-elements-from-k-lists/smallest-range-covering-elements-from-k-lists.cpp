class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        //val, listind, ind
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> , greater<>> pq;
        int k = nums.size();

        int maxEle = INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],{i,0}});
            maxEle = max(maxEle , nums[i][0]);
        }

        vector<int> ans_range = {-1000000, 1000000};

        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int minEle = f.first;
            int listInd = f.second.first;
            int ind = f.second.second;

            //update if better answer is found
            if(maxEle - minEle < ans_range[1]-ans_range[0]){
                ans_range[0] = minEle ;
                ans_range[1] = maxEle;
            }


            if(ind+1 < nums[listInd].size()){
                pq.push({nums[listInd][ind+1],{listInd,ind+1}});
                maxEle = max(maxEle , nums[listInd][ind+1]);
            }
            else break; //ind out of bound hojaegi

        }

        return ans_range;
    }
};