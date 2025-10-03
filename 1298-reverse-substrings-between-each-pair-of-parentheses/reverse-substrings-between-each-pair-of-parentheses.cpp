class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> openingBracketInd; 
        vector<int> door_mapping_brackets(n);

        for(int i=0;i<n;i++){
            if(s[i]=='(') openingBracketInd.push(i);
            else if (s[i]==')'){
                int j= openingBracketInd.top();
                openingBracketInd.pop();
                door_mapping_brackets[i] = j;
                door_mapping_brackets[j]= i;
                
            }
        }

        string ans = "";

        int direction =1;
        for(int i=0;i<n;i+=direction){
            if(s[i]=='(' || s[i] == ')'){
                i = door_mapping_brackets[i]; 
                // go to the respective opposite bracket and iterate in opposite direction
                direction = -direction; //opposite ulta direction mein jaana hai 
            }
            else{
                ans += s[i];
            }
        }


    return ans;


    }
};