class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;

        int n = nums.size() ;
        if(n==0 || n==1) return n ;

        int max_len = 1 ;
        int curr_len = 1 ;

        for(int i = 0 ; i<n-1 ;i++) 
        {
            if(nums[i]==nums[i+1]) continue ;
            if(nums[i]+1 == nums[i+1])
            {
                curr_len++ ;
                max_len = max(max_len,curr_len) ;
            }

            else{
                curr_len = 1 ;
            }
        }

        return max_len ;
    }
};