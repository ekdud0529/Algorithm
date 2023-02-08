class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                return (mid);
            }
            if(nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if(nums[right] < target) right++;
        return (right);
    }
}
