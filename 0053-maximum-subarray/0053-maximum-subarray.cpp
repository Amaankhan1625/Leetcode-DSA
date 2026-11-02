class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;

        int sum = nums[0] ;
        int max_sum = nums[0] ;

        for(int i = 1 ; i < n ;i++)
        {
            int x = nums[i] ;
            sum = max(sum+x,x);
            max_sum = max(sum,max_sum);
        }

        return max_sum ;
    }
};