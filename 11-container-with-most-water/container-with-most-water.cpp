class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area =0;
        int n=height.size();
        
        int s=0, e=n-1;
        
        while(s<e){
            
            int temp_area = min(height[s],height[e])*(e-s);
            area = max(area,temp_area);
            
            if(height[s]<height[e]) s++;  //arr[s]<arr[e] means arr[s] ki height kamm hai , usko badaane ke liye aage jaaega
            else e--; //e ki height kamm hai
        }
     
   
    return area;
    }
};