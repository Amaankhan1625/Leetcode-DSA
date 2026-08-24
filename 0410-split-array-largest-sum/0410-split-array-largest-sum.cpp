class Solution {
public:
bool cansplit(vector<int>& nums,int k ,long long maxsum)
{
    int subarray = 1 ;
    long long currentsum = 0 ;

    for(int x :nums) 
    {
        if(currentsum + x > maxsum)
        {
            subarray++ ;
            currentsum = x ;
           if(subarray > k)
         {
            return false;
         }  
        }
        else{
           currentsum=currentsum+ x;
        }

    }
return true ;

}

  int splitArray(vector<int>& nums, int k) {
        long long low = * max_element(nums.begin(),nums.end()) ;
        long long high = accumulate(nums.begin(),nums.end(),0LL) ;

        long long answere = high ;

        while(low <= high){
            int mid = low + (high - low)/2 ;

            if(cansplit(nums,k,mid))
            {
                answere = mid ;
                high = mid - 1 ;
            }
            else{
                low = mid + 1 ;
            }
        }

        return answere ;
        
    }
};