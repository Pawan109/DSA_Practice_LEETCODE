class Solution {
public:

    bool isPossible(vector<int> &weights, int d_days, int mid){

        int days =1; //start days =1 ******
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum>mid){
                days++;
                sum = weights[i];
            }
            if(days > d_days) return false;
        }
    return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
         
        //capacity of the boat is not given , that , we have to assume 
        //min capacity of the boat should be max_element in the array -> because 
        //kisi na kisi day par we have to ship that weight // toh minimum itni capacity toh honi hi chahiye boat ki
        
        //maximum capacity of the boat -> sum of all weights
        //toh itni capacity hui toh 1 din mein hi we will be able to ship all the packages
        //but we dont' want to ship in 1 day , we want to ship within N Days
        //so that is just the max range, max capacity a boat can have
        //and not a part of answer
        ///my answer will be in the range max_element to total sum . 
        
        //if weight exceeds capacity --> days++
        //as there is only ship , and it can't take more than capacity so it will come on another day to take that weight 
        
        //how to decide the capacity ?? -> mid tak ke wweights lelete hai // mid will be my capacity 
    
    //if sumofweights > mid -> i can't take this much weight -> i will return again with the ship tmrw on the next day 
    //-> do days++
    //if its possible to ship these weights within Ddays -> store answer -> look for a better answer
    // store min_capacity -> lets try with even less capacity -> how? => e = mid-1  // taking less weights -> mid will be reduced-> capacity will be reduced . 

        int s = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for(auto x:weights) sum+=x;
        int e = sum;

        int min_capacity = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(isPossible(weights,days,mid)){
                min_capacity = mid ;
                e = mid-1;
            }
            else s = mid+1;
        }
    return min_capacity;
    }
};