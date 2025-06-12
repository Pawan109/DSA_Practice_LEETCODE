class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //max heap
        priority_queue< pair<int,int>> pq ;//diff, arr[i]

        for(int i=0;i<arr.size();i++){

            pq.push({abs(x-arr[i]), arr[i]});
            if(pq.size()>k) pq.pop();

        }

//so now in pq i will have the k closest elements , how? 
//dry run array: 2 3 7 8 9   x: 7  k=2 

    //push this into ans 
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

sort(ans.begin(),ans.end());
return ans;

    }
};