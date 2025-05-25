class Solution {
    public int longestPalindrome(String[] words) {
        
        Map<String,Integer> mymap = new HashMap<>();
        int result = 0;

        for(String word: words){
            String rev = new StringBuilder(word).reverse().toString();
            
            if(mymap.getOrDefault(rev,0)>0) {
                result += 4;
                mymap.put(rev, mymap.get(rev)-1);//key val insert karre hai .
            }
            else  mymap.put(word,mymap.getOrDefault(word,0)+1);
        }


        for(Map.Entry<String,Integer> entry : mymap.entrySet()){
            String word = entry.getKey();
            int count = entry.getValue();

            if(word.charAt(0) == word.charAt(1) &&  count ==1){
                result += 2; 
                break;
            }
        }

    return result;

    }
}