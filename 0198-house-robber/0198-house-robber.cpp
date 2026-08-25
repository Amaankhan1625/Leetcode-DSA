class Solution {
public:
int helper(vector<int>& nums,int i,int n ,vector<int>& dp)
{
   if(i>=n) return 0 ;

   if(dp[i]!=-1) return dp[i] ;

   //rob the house 
  int robhouse = nums[i] +  helper(nums,i+2,n,dp) ;

   //ignore the house 
   int skiphouse = helper(nums,i+1,n,dp) ;

   return dp[i] = max(skiphouse , robhouse) ;


}
    int rob(vector<int>& nums){
        int n = nums.size() ;

        vector<int> dp(n,-1) ;

        return helper(nums,0,n,dp) ;
        
    }
};