class Solution {
public:

int calculate(vector<int>& nums,int mid)
{
    int day = 1 ;
    int temp = mid ;
    for(int x : nums)
    {
        if(temp >= x)
        {
            temp = temp-x ;
        }
        else{
            day++ ;
            temp = mid ;
            temp = temp-x ;
        }
    }
    return day ;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end()) ;
        int high  = accumulate(weights.begin(),weights.end(),0);

        while(low<high)
        {
            int mid = low + (high - low)/2 ;

            if(calculate(weights,mid) > days)
            {
                low = mid + 1 ;
            }
            else{
                high = mid ;
            }
        }

        return low ;
        
    }
};