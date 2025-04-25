class Solution {
public:
    bool isPossible(vector<int> & bloomDay, int m, int k, int mid){
        //present_day  is nothing but mid // which will be taken fromt he minDays fn
        int flower_count=0;
        int bouquet_count=0;
        
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){ //mtlb it has bloomed before the taken day(mid)
                 flower_count++;
                if(flower_count >=k){ 
                    bouquet_count++;  
                    flower_count=0;//updating flower_count for the next bouquet 
                }
            }
            else flower_count=0;//abhi tak bloom nahi kiya hai flower, and i can only pick continuos flowers for a bouquet toh current flower bloom nahi hua hai, toh i have to start from flower 0 again for the next bouquet. 
            
        }
        if(bouquet_count>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // very similar to allocate min no. of pages 
        int s = *min_element(bloomDay.begin(),bloomDay.end()); //1st day hi saaare bloom karlein
        int e= *max_element(bloomDay.begin(), bloomDay.end());//lastday tak bloom na karein 
        // but mai exactly kitne din lu , jisme mujhe required flower bloom hojaye, aur required no. of bouquets ban jaaye? -> yahi toh nikaalna hai -> binary search on answers-> answer lies between s and e 

        // mai mid days leke dekhta hu, if itne days mein flowers bloom and we get required no. of bouquets. 

        int min_days =-1;
       // if(bloomDay.size()< (m*k)%(1e9+7)) return -1;//base case /bakwaaaaaaaaaaaaaaaas

        while(s<=e){
            int mid = s+(e-s)/2;  //itne days leke dekhta hu . 

            if(isPossible(bloomDay, m , k, mid)){
                min_days = mid ;//mid no. of days lagenge 
                e= mid-1; // still in search of a better answer
            }
            else s= mid+1;
        }
        return min_days;
    }
};