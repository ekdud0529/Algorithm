class Solution {
    public int pivotIndex(int[] nums) {
        for(int i=1; i<nums.length; i++)
        {
            nums[i] += nums[i-1];
        }
        if((nums[nums.length - 1] - nums[0]) == 0)
            return (0);
        for(int i=1; i<nums.length; i++)
        {
            int left = nums[i - 1];
            int right = nums[nums.length - 1] - nums[i];
            if(left == right)
            {
                return (i);
            }
        }
        return (-1);
    }
}
