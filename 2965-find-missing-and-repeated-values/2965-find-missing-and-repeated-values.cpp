class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp ;
        int n = grid.size() ;

        for(int i = 0 ; i < n ; i++) 
        {
            for(int j = 0 ; j < n ; j++)
            {
                mpp[grid[i][j]] ++ ;
            }
        }
        int i = 1 ;
        int missing = 0 ;
        int repeat = 0 ;

        
        // Check numbers from 1 to n*n
        for (int i = 1; i <= n * n; i++) {

            if (mpp[i] == 0) {
                missing = i;
            }
            else if (mpp[i] == 2) {
                repeat = i;
            }
        }
        return {repeat,missing} ;
    }
};