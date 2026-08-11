class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

       unordered_map<int,int> mpp ;
        vector<int> ans ;

        for(int x : nums) 
        {
            mpp[x]++ ;
        }

        int n = nums.size() ;

        for(auto& it : mpp) 
        {
            if(it.second > n/3)
            {
                ans.push_back(it.first) ;
            }
        }

        return ans ;
    }
};