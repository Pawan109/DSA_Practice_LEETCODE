class Solution {
public:

    void helper(string digits, string temp, int ind, string mapping[], vector<string>&ans){

        if(ind == digits.size()){
            ans.push_back(temp);
            return;
        }

        int string_ind = digits[ind]-'0' ; //jaise digits = "23"  digits[0] ="2" -> convert to int
        string string_val = mapping[string_ind];

        for(int i=0;i<string_val.size();i++){
            temp.push_back(string_val[i]);
            helper(digits,temp,ind+1,mapping,ans);
            temp.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size()==0) return ans;
        int ind=0;
        string temp;
        helper(digits,temp,ind,mapping,ans);
        return ans;
    }
};