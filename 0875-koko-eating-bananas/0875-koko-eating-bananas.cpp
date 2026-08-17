class Solution {
public:
int calculate(vector<int>& piles,int k)
{
    int n = piles.size() ;
    int ans =0 ;

    for(int i = 0 ; i < n ; i++)
    {
        ans = ans + (piles[i]+k-1)/k ;
    }

    return ans ;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 ;
        int high = *max_element(piles.begin(),piles.end()) ;

        while(low < high)
        {
          int mid = low + (high-low)/2 ;

          if(calculate(piles,mid)<=h)
          {
            high = mid ;
          }

          else{
            low = mid+1 ;
          }
        }

          return low ;
    }
};