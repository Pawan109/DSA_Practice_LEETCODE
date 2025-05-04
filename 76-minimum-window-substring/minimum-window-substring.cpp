class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char,int> mymap;

        for(auto x: t) mymap[x]++;

        int start_ind = -1;
        int min_window = INT_MAX;
        int req_chars_count = t.size();

        int i=0, j=0;
        while(j<s.size()){
            char ch_j = s[j];
            if(mymap[ch_j]>0) req_chars_count--;

            mymap[ch_j]--;

            while(req_chars_count == 0 ){ //try to shrink window and find better ans

                if(min_window > j-i+1){
                    min_window = j-i+1;
                    start_ind = i;
                }

                char ch_i = s[i];
                mymap[ch_i]++;
                if(mymap[ch_i] > 0) req_chars_count++;

                i++;

            }
            
           j++; 
        }
    return  min_window==INT_MAX ? "" : s.substr(start_ind,min_window);
    }
};