class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
      int pos =-1;// index of closest element

      int s = 0, e=arr.size()-1;

      while(s<=e){
        int mid = s+(e-s)/2;

        if(arr[mid]==x){
            pos = mid;
            break;
        }else if(arr[mid]<x){
            s=mid+1;
            pos = mid;
        }
        else e = mid-1;

      }
//two pointers left , rght
    int left = pos;
    int right = pos+1;
    
    while(k>0 && left>=0 && right<arr.size()){
        
        int diff1 = abs(arr[left] - x);
        int diff2 = abs(arr[right] -x);

        if(diff1<= diff2){
            ans.push_back(arr[left]);
            left--;
        }
        else{
            ans.push_back(arr[right]);
            right++;
        }

        k--;
    }

    while(k>0 && left>=0){
        ans.push_back(arr[left]);
        left--;
        k--;
    }

    while(k>0 && right<arr.size()){
        ans.push_back(arr[right]);
        right++;
        k--;
    }

    sort(ans.begin(),ans.end());
    return ans;

    }
};