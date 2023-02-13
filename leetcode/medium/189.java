class Solution {
    public void rotate(int[] nums, int k) {
        int size = nums.length;
        int ans[] = new int[size];
        
        k %= size;
        for(int i=0; i < k; i++)
        {
            ans[i] = nums[size - k + i];
        }
        for(int i=0; i < size - k; i++)
        {
            ans[k + i] = nums[i];
        }
        for(int i=0; i<size; i++)
        {
            nums[i] = ans[i];
        }
    }
}
