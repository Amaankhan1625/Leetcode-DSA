class Solution {
public:
    bool isIsomorphic(string s, string t) {
    string temp  = s ;

         if(s.length() != t.length()) false; 


        map<char,int>s1;
       map<char,int>s2;
       int n = s.length();
       int i = 0;

       while(n>=i)
       {
        //store indexes of each char in 1st map  of string s
         if(s1.find(s[i]) == s1.end())
         {
           s1[s[i]] = i;
         }
         //store indexes of each char in 2nd map  of string t
         if(s2.find(t[i]) == s2.end())
         {
           s2[t[i]] = i;
         }
 //compare
          if(s1[s[i]]!=s2[t[i]]) return false;

            i++; 
       }
return true;
        
    }
};