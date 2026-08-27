class Solution {
public:
    string reverseWords(string s) {
        string ans = "" ;
        string temp = "" ;

        for(int i =0 ; i<s.length(); i++)
        {
          if (s[i] == ' ') {

                // Ignore multiple spaces
                if (temp.empty()) {
                    continue;
                }

                if (ans.empty()) {
                    ans = temp;
                }
                else {
                    ans = temp + ' ' + ans;
                }

                // Clear after processing the word
                temp = "";
            }
           else{
             temp = temp + s[i] ;
           }
        }

         // Process the last word
        if (!temp.empty()) {
            if (ans.empty()) {
                ans = temp;
            }
            else {
                ans = temp + ' ' + ans;
            }
        }

        return ans;

        return ans ;
    }
};