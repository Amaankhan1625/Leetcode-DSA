class Solution {
public:


int helper(int n , int m,int i , int j , vector<vector<int>>& dp,vector<vector<int>>& grid)
{

     // Outside grid
        if (i >= n || j >= m)
            return INT_MAX;


    if(i == n-1 &&j == m-1 ) return grid[i][j] ;

      // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

    //down
    int down = helper(n,m,i+1,j,dp,grid);

    //right
    int right = helper(n,m,i,j+1,dp,grid) ;

    return dp[i][j] = grid[i][j] + min(down,right) ;
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> dp(n,vector<int>(m,-1)) ;

        int ans = helper(n,m,0,0,dp,grid) ;

        return ans ;
        
    }
};