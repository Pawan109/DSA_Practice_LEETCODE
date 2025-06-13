class Solution {
public:

    bool isPossible(vector<int>& position, int m, int mid){
        int prev = position[0];//placed the first ball here
        int countBalls = 1;//pehli ball ko place kardiya 0 pe

//start loop from 1 as we placed first ball at 0
        for(int i=1;i<position.size();i++){
            int curr = position[i]; //place the ball at position[i]

            if(curr-prev>=mid){ //if dono balls ke beech ka dist (force) is >= mid (i.e min dist)
                countBalls++;//matlb sahi place kiya hai balls ko
                prev=curr; //now ball2 will be at curr which will be the newprev, and we will place ball 3 
            }

            if(countBalls==m) break;
        }

        return (countBalls==m)?true:false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n= position.size();
        //position matlb no. line, toh sbse pehle number line sort krlo 
        sort(position.begin(), position.end()); 

//min force between two magneticballs -> both are adjacent -> a[i] and a[i+1], dist between them =1 
//max force b/w two balls -> ek first position mein , ek last position mein .
        int s=1;
        int e=  position[n-1] - position[0]; //sbse last kiss position mein rakh skte hai ball ko 

        // suppose 1 2 3 4 7 is my number line, and no. of magnetic balls m=3
        //toh balls ko 1 2 and 3 pe rakha -> minforce between them is 3 
        //we can increase the min force
        //say balls are placed at min dist of 2, so we place it at 1 3 7   min((3-1),(7-3)) ==2
        ///--> min dist 2 is also possible
        ///now lets go and try for min dist of 3 // so we place it at 1 4 and 7  min((4-1),(7-4))==3
        //so min dist 3 is also possible 

        //toh ese we have to get maximum possible minium distnace (distance or force same thing)

        //and we know answer lies between 1 to (position[n-1] - position[0])
        //so we are basically starting from 1 and increasing the min dist eventually going towards (position[n-1] - position[0])  i.e our search space
        // so this will be binary search on answer , ans lies b/w s & e 

        //lets say we take mid as  distance 
        //and if its possible to place m balls with mid min dist, then we will store it in our ans 
        //and look for a better ans i.e s=mid+1 (maximum minimal distance)
        int ans =0;
        while(s<=e){
            int mid = s+(e-s)/2;

            if(isPossible(position,m,mid)){
                ans = mid;
                s = mid+1;
            }
            else e=mid-1;
        }

        return ans;


    }
};