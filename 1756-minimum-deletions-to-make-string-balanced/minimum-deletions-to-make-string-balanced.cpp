class Solution {
public:
    int minimumDeletions(string s) {
        
        int count_right_a = 0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a') count_right_a++;
        }

        int count_b = 0;

    int min_deletions = INT_MAX;

        for(int i=0;i<s.size();i++){
        
            if(s[i]=='a') count_right_a--;

            min_deletions= min(min_deletions, count_b + count_right_a);

            if(s[i]=='b') count_b++;

        }

    return min_deletions;

    }
};