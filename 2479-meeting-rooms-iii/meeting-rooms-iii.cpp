class Solution {
public:

    typedef pair< long long , int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin(), meetings.end());

        vector<int> roomsUsedCount(n,0);

        priority_queue< P, vector<P> , greater<P>> usedRooms;

        priority_queue<int , vector<int> , greater<int> > unUsedRooms;

        for(int room= 0;room<n;room++){
            unUsedRooms.push(room);
        }

        for(vector<int> &meet: meetings){
            int start = meet[0];
            int end = meet[1];

            //lets first check by this , which rooms are available again 
            while(!usedRooms.empty() && start >= usedRooms.top().first){
                int room = usedRooms.top().second;
                usedRooms.pop();
                unUsedRooms.push(room);
            }

            //if rooms are available
            if(!unUsedRooms.empty()){
                int room = unUsedRooms.top();
                unUsedRooms.pop();
            usedRooms.push({end,room});
                roomsUsedCount[room]++;
            }
            else{ //if rooms are not available 
                long long endTime= usedRooms.top().first;
                int room= usedRooms.top().second;

                usedRooms.pop();
                usedRooms.push({endTime +(end-start), room});
                roomsUsedCount[room]++;
                
            }
        


        }

    int resultRoom = -1;
    int maxUsed = 0;
    for(int room = 0;room<n;room++){
        if(roomsUsedCount[room] > maxUsed){
            maxUsed = roomsUsedCount[room];
            resultRoom = room;
        }
    }

    return resultRoom;

    }
};