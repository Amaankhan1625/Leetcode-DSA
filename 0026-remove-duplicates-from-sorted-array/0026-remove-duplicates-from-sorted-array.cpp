class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 0;

        for (int h = 1; h < nums.size(); h++) {
            if (nums[h] != nums[l]) {
                l++;
                nums[l] = nums[h];
            }
        }

        return l + 1;
    }
};