class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end()) ;

        string first = strs.front() ;
        string last = strs.back() ;

        int minlen = min(first.length(),last.length()) ;

        int i = 0 ;

        while(i < minlen && first[i] == last[i])
        {
            i++ ;
        }

        return first.substr(0,i) ;
    }
};