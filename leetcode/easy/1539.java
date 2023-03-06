class Solution {
    public int findKthPositive(int[] arr, int k) {
        int index = 0;
        int num = 0;
        int cnt = 0;

        while (k != cnt)
        {
            num++;
            if((index < arr.length) && (arr[index] == num))
            {
                index++;
            }
            else
            {
                cnt++;
            }
        }
        return (num);
    }
}
