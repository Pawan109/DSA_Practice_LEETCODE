class Solution {
public:
    string addStrings(string X , string Y) {
          string ans ="";
        int carry =0;
        int i = X.size()-1, j = Y.size()-1;
        int sum;
        while(i>=0 && j>=0){
            
             sum = X[i]-'0'  + Y[j]-'0' + carry;
            
            ans += sum%10 +'0'; //again converting it to a char
            carry = sum/10; //but isko don't convert , as isko toh sum ke saath add krna hai
            
            i--;
            j--;
            
          }
          
          while(i>=0){
              sum= X[i]-'0'+carry;
              ans+= sum%10 +'0';
              carry = sum/10;
              i--;
          }
          while(j>=0){
              sum = Y[j]-'0'+carry;
              ans+= sum%10 +'0';
              carry = sum/10;
              j--;
          }
          //now its all about the base cases
         
         //1. what if theres an extra carry left at the beginning 
         // then we have to insert that carry at the beginning 
        if(carry>0){
            ans+=carry+'0'; 
        }
         //2. what if starting chars are '0' then if we return our string it will return us 000..123
         //but we just want 123 
         //but if directly we run the for look and look for 0s then it will return us the count of 0s
         //so we will start from i=0 , and if there are no 0s we will break 
         
         
      /*   while(ans.back()=='0') ans.pop_back();
         if(ans.size()==0) return "0"; //pop krte krte 0 hogyi toh
         */
         reverse(ans.begin(),ans.end());
         
         
        int starting0s =0;
         for(int i=0;i<ans.size();i++){
             if(ans[i]=='0') starting0s++;
             else break;
         }
         
         if(starting0s==ans.size()) return "0"; //means all the chars are 0 
         
         ans= ans.substr(starting0s); // X would start from non zero value
        
        
         return ans;
    }
};