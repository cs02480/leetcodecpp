class Solution {
    private:
    string expend(string s,int lo,int hi)
    {
        int len = s.length();
        
        while(lo>=0 && hi<len && s[lo] == s[hi])
        {
            lo--,hi++;
        }
        
        return s.substr(lo+1,hi-lo-1);
    }
public:
    string longestPalindrome(string s) {
        
        int len = s.length();
        string max_str = "",cur;
        int max_len =0,cur_len;
        
        for(int i=0;i<len;i++)
        {
            cur = expend(s,i,i);
            cur_len = cur.length();
            if(cur_len > max_len)
            {
                max_len = cur_len;
                max_str = cur;
            }
            
            cur = expend(s,i,i+1);
            cur_len = cur.length();
            if(cur_len > max_len)
            {
                max_len = cur_len;
                max_str = cur;
            }
        }
        return max_str;
        
    }
};