class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length== 0) return 0;

        Set<Integer> myset = new HashSet<>();

        for(int x: nums) myset.add(x);
        
        int ans = 0;

        for(int x: myset){

            if(!myset.contains(x-1)){
                int curr = x;
                int count  = 0;

                while(myset.contains(curr)){
                    count++;
                    curr++;
                }

                ans = Math.max(ans,count);
            }


        }

    return ans;

    }
}