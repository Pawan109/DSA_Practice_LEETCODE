class Solution {
public:


    // void lps(string pat, vector<int> &lps){
    //     int len = 0;
    //     int i =1;
    //     lps[0]=0;

    //     while(i<pat.size()){
    //         if(pat[i]==pat[len]){
    //             len++;
    //             lps[i]=len;
    //             len++;
    //         }else{
    //             if(len!=0){
    //                 len = lps[len-1];
    //             }else{
    //                 lps[i]=0;
    //                 i++;
    //             }
    //         }
    //     }
    // }

    string longestPrefix(string s) {
         int n = s.length();
        vector<int> lps(n, 0);
        int len = 0;

        // Build LPS
        for(int i = 1; i < n; i++) {
            while(len > 0 && s[i] != s[len]) {
                len = lps[len - 1];  // fallback
            }

            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
            } else {
                lps[i] = 0;
            }
        }

        // lps[n-1] is the length of longest prefix which is also suffix
        return s.substr(0, lps[n - 1]);
    }
};