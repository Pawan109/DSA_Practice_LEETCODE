class Solution {
public:
    int halveArray(vector<int>& arr) {
        int count =0;
        priority_queue<double> pq;
        
        double sum = 0;
        
        for(auto x: arr){
            pq.push(x);
            sum +=x;
        }
        
        double req_sum = sum/2.0;
        
        while(sum > req_sum){
            double top = pq.top();
            pq.pop();
            
            sum -= top;
            sum += top/2.0 ;
            
            pq.push(top/2.0);
            count++;
        }
        
        return count;
    }
};