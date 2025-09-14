class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
             //min-heap -> freq,ele
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        
        //count frequency of each element
        // Worst Case - n distinct elements are stored, so, space O(n)
        unordered_map<int, int> mymap;
        for(auto x: nums) mymap[x]++;

        
        //Push in min-heap and maintain size k
        for(auto x:mymap) {
            pq.push({x.second, x.first});  //pq min heap sorted acc to freq 
            
            if(pq.size() > k)
                pq.pop();
        }
        
        
        //Pick all top K elements
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};