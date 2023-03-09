class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int smaller = 10000;
        int price = 0;

        for(int i=0; i<prices.length; i++)
        {
            if(prices[i] < smaller)
            {
                smaller = prices[i];
            }
            price = prices[i] - smaller;
            if(price > ans)
            {
                ans = price;
            }
        }
        return (ans);
    }
}
