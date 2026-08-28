class Solution {
public:
    int maxDepth(string s) {
        int n = s.length() ;
        stack<int> st ;
        int max_count = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
          if(s[i] == '(')
          {
            st.push(s[i]) ;
            max_count = max(max_count,(int)st.size()) ;
          }

          else if(s[i] == ')')
          {
            st.pop() ;
          }
          else{
            continue ;
          }
        }
return max_count ;
    }
};