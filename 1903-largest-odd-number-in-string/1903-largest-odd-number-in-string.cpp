class Solution {
public:
    string largestOddNumber(string num) {
        string ans = num ;
        int n = num.length() ;
        int i = n-1 ;

        while(i>=0)
        {
           int number = num[i] - '0' ;
           if(number % 2 == 0)
           {
             i-- ;
           }
           else{
            break ;
           }
        }
        if(i<0) return "";

        return num.substr(0,i+1) ;
    }
};