class Solution {
public:

    typedef pair<int, pair<int,int>> P ; //sum, index in num1, num2

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int  m = nums2.size();
        vector<vector<int>> ans;

        priority_queue< P, vector<P> , greater<P>> pq; //min heap . 
        //yes we are not using maxheap for k smallest elements, kyuki hamm check hi karre hai top k elements

        set<pair<int,int>> vis; 

        vis.insert({0,0});

        int sum = nums1[0] + nums2[0];
        pq.push({sum ,{0,0}});

        while(k-- && !pq.empty()){

            auto f = pq.top();
            pq.pop();

            int i = f.second.first;
            int j = f.second.second;

            ans.push_back({ nums1[i], nums2[j]});

             //Push (i, j+1) if possible  ->this indices exists and we haven't previously considered them.
            if(j+1<m && vis.find({i,j+1})==vis.end()){
                pq.push({nums1[i]+ nums2[j+1] ,{i,j+1}});
                vis.insert({i,j+1});

            }
            
            //push (i+1,j ) if possible-> i.e if indices exist and we haven't previously taken them . 
            if(i+1<n && vis.find({i+1,j})==vis.end()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                vis.insert({i+1,j});
            }

        }


    return ans;


    }
};