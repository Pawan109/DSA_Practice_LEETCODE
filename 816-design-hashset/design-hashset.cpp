class MyHashSet {
public:

    int numBuckets; ///size of buckets.
    vector<list<int>> buckets;
    int getHashValue(int key){  //we have made this method.. not by default. 
        return key%numBuckets;
    }


    MyHashSet() { //constructor-> for initializing
        numBuckets = 15000;//atmost 10^4 calls will be made assuming (given in question)
        buckets = vector<list<int>>(numBuckets,list<int>{});//initializing empty vector<list<int..
    }
    
    void add(int key) {
        //1. key-> hashcode -> bucketindex  ---> find index    -> this will tellus the bucket no.
        //2. check if it is  present there alredy in that bucket 
        // if not present -> add it 
        int ind = getHashValue(key);
        auto itr = find(buckets[ind].begin(), buckets[ind].end(),key);

        if(itr == buckets[ind].end()) buckets[ind].push_back(key);
    }
    
    void remove(int key) {
        //1. key-> hashcode -> bucketindex -->find this index
        //2. check if present there in that bucket
        //if present delete it 
        int ind = getHashValue(key);
        auto itr = find(buckets[ind].begin(),buckets[ind].end(),key);

        if(itr != buckets[ind].end()) buckets[ind].erase(itr);
    }
    
    bool contains(int key) {
        //1. key-> hashcode-> bucketindex -> find this index
        //2. check if present there in that bucket -> if yes -> return true 
        int ind = getHashValue(key);
        auto itr = find(buckets[ind].begin(), buckets[ind].end(), key);
        
        
        return (itr != buckets[ind].end()) ;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */