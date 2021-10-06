class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int first, second;
        first = 0;
        second = 0;
        int n = nums.length;
        int sum = 0;
        int minLength = 65536;
        while(second < n)
        {

            if(second != n)
                sum += nums[second++];
            if(second == n && sum < target && minLength == 65536)
                return 0;
            while(sum >= target && first != n)
            {
                sum -= nums[first++];
                minLength = Math.min(minLength, second - first + 1);
            }
        }
        if(minLength == 65536)
            minLength = 0;
        return minLength;
    }
}
