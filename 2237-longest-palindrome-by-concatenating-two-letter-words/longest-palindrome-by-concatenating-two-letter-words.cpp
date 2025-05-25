class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string , int> mymap;

        int result = 0;
        for(auto &word : words){

            string rev_word = word;
            swap(rev_word[0], rev_word[1]);

            if(mymap.find(rev_word)!=mymap.end() && mymap[rev_word] > 0){
                result+=4;
                mymap[rev_word]--;
            }
            else mymap[word]++;
        }

        //now if aa ->i.e strings with same chars
        //if they are repeated twice -> upar for loop me already handled hoga ye
        //but if they appear only once, toh we can add them in middle and string will still be a palindrome. 
        //but we can only take one such word, as lccl is palindrome, lcppcl is palindrom but lcppqqcl is not palindrome.

        for(auto x: mymap){
            string word = x.first;
            int freq = x.second;

            if(word[0]==word[1] && freq==1){
                result+=2;
                break;
            }
        }
return result;

    }
};