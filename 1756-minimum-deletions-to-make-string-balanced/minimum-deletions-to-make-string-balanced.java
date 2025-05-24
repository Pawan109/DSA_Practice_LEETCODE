class Solution {
    public int minimumDeletions(String s) {
        int count_right_a = 0;

        for(int i=s.length()-1; i>=0;i--){
            if(s.charAt(i)=='a') count_right_a++;
        }

        int count_b=0;
        int min_deletions = Integer.MAX_VALUE;

        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='a') count_right_a--;
            
            min_deletions = Math.min(min_deletions, count_b + count_right_a);

            if(s.charAt(i)=='b') count_b++;
        }
    return min_deletions;
    }
}