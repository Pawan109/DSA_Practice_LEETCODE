class Solution {
public:
    int minAddToMakeValid(string s) {
          int closeBracket_count = 0;
        stack <char> st;
        for(char ch : s){
            if (ch == '(') st.push(ch);
            else
                if (st.empty()) closeBracket_count ++; //close bracket aaya aur pop krne k liye stack mein kuch nai hai
                else st.pop();
                
        }
        return closeBracket_count + st.size();
    }
};