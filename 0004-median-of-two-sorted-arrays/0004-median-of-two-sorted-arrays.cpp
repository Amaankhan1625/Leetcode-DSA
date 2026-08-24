class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
       int n = nums1.size();
       int m = nums2.size();

        int total = n + m ;
        int half = (total + 1) / 2;

        int low = 0 ;
        int high = n;

        while(low <= high)
        {
            int cut1 = (low + high) / 2;
            int cut2 = half - cut1;

            int LA = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int RA = (cut1 == n) ? INT_MAX : nums1[cut1];

            int RB = (cut2 == m) ? INT_MAX : nums2[cut2];
            int LB = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

             if (LA <= RB && LB <= RA) {
                if (total % 2 == 0)
                    return (max(LA, LB) + min(RA, RB)) / 2.0;
                else
                    return max(LA, LB);
            }
            else if (LA > RB)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0;
    }
};