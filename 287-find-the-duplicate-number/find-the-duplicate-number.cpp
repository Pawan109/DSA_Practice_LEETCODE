class Solution {
public:
    int findDuplicate(vector<int>& arr) {
            
        int slow = arr[0];
        int fast = arr[0];
        
        while(true){
            slow = arr[slow];
            fast = arr[arr[fast]];
            if(slow==fast) break;
        }
        
        fast = arr[0];
        
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        
        return fast;
    }
};