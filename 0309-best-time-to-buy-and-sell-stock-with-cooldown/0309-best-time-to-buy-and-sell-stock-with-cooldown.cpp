class Solution {
public:
int profit(bool canBuy,int ind ,vector<vector<int>>& dp,vector<int>& prices)
{
    if(ind >= prices.size()) return 0 ;

     // Already calculated
        if (dp[ind][canBuy] != -1) {
            return dp[ind][canBuy];
        }

     int ans;

        if (canBuy) {

            // Buy
            int buy = -prices[ind] +
                      profit(false, ind + 1, dp, prices);

            // Skip
            int skip = profit(true, ind + 1, dp, prices);

            ans = max(buy, skip);

        } else {

            // Sell
            int sell = prices[ind] +
                       profit(true, ind + 2, dp, prices);

            // Don't sell
            int skipSell = profit(false, ind + 1, dp, prices);

            ans = max(sell, skipSell);
        }

        return dp[ind][canBuy] = ans;
}
    int maxProfit(vector<int>& prices) {
         int n = prices.size() ;

          vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return profit(1, 0, dp, prices);
    }
};