class Solution {
    public void moveZeroes(int[] nums) {
        int cnt = 0;

        for(int i=0; i<nums.length; i++)
        {
            if(nums[i] == 0)
            {
                ArrSwap(i, nums);
                cnt++;
            }
        }
    }

    public void ArrSwap(int index, int[] nums)
    {
        for(int i=index+1; i<nums.length; i++)
        {
            if(nums[i] != 0)
            {
                nums[index] = nums[i];
                nums[i] = 0;
                return ;
            }
        }
    }
}
