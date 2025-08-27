class Solution {
public:
    int triangleNumber(vector<int>& arr) {
        int count = 0 ;
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        int i = n-1; 
        
        while(i>=2){
            int s=0;
            int e=i-1;
            while(s<e){
                if((arr[s]+arr[e]) <= arr[i] ) s++;
                else{
                     count+= (e-s);
                     e--;
                }
            }
            i--;
        }
        
      
        return count;
    }
};