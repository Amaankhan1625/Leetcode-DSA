class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n  = s.length();
        int l = 0;
        int h = n-1;

        while (l < h) {
            // Skip non-alphanumeric characters from the left
            while (l < h && !isalnum(s[l])) {
                l++;
            }
            // Skip non-alphanumeric characters from the right
            while (l < h && !isalnum(s[h])) {
                h--;
            }

            // Compare lowercased characters
            if (tolower(s[l]) != tolower(s[h])) {
                return false;
            }

            l++;
            h--;
        }


        return true;
    }
};