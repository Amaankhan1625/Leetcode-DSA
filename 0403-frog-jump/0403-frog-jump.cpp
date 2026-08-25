class Solution {
public:

map<pair<int, int>, bool> dp;

bool helper(int pos , int jump,vector<int>& stones,unordered_set<int>& st)
{
    if(pos == stones.back())
    {
        return true ;
    }

      // Already calculated this state
        if (dp.count({pos, jump}))
        {
            return dp[{pos, jump}];
        }

        // Try jumps: k-1, k, k+1
        for (int nextjump = jump - 1;
             nextjump <= jump + 1;
             nextjump++)
        {
            if (nextjump <= 0)
            {
                continue;
            }

            int nextpos = pos + nextjump;

            // Frog can only land on a stone
            if (st.count(nextpos))
            {
                if (helper(nextpos, nextjump, stones, st))
                {
                    return dp[{pos, jump}] = true;
                }
            }
        }

        return dp[{pos, jump}] = false;

}

    bool canCross(vector<int>& stones) 
    {
       unordered_set<int> st(stones.begin() , stones.end()) ;

        return helper(0 , 0 , stones, st) ;;
    }
};