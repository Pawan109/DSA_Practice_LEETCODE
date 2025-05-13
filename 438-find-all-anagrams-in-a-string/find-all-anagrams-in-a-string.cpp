class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> arr(26,0);

        for(auto &x: p) arr[x-'a']++;

        int m = s.size(), pat_size = p.size();

        int i =0,j=0;
        vector<int> ans;

        while(j<m){
            arr[s[j]-'a']--;

            if(j-i+1==pat_size){
                if(arr == vector<int>(26,0))  ans.push_back(i);

                arr[s[i]-'a']++;
                i++;
            }

           j++; 
        }

return ans;
    }
};