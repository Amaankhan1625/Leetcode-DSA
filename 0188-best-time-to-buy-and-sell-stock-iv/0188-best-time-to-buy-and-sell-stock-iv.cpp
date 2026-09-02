class Solution {
public:
 int profit(bool canBuy,int ind ,vector<vector<vector<int>>>& dp,vector<int>& prices,int count)
{
    if(ind == prices.size() || count == 0) return 0 ;

     // Already calculated
        if (dp[ind][canBuy][count] != -1) {
            return dp[ind][canBuy][count];
        }

     int ans;

        if (canBuy) {

            // Buy
            int buy = -prices[ind] +
                      profit(0, ind + 1, dp, prices,count);

            // Skip
            int skip = profit(1, ind + 1, dp, prices,count);

            ans = max(buy, skip);

        } else {

            // Sell
            int sell = prices[ind] +
                       profit(1, ind + 1, dp, prices,count-1);

            // Don't sell
            int skipSell = profit(0, ind + 1, dp, prices,count);

            ans = max(sell, skipSell);
        }

        return dp[ind][canBuy][count] = ans;
}
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size() ;

          vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k+1, -1))) ;

        return profit(true, 0, dp, prices,k);
    }
};