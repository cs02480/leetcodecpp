class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> map;
        
        int start_index=0;
        int max_len = 0;
        int len = s.length();
        for(int i =0;i<len;)
        {
            if(map.find(s[i]) == map.end())
            {
                map[s[i]] =1;
                if((i-start_index+1)> max_len)
                {
                    max_len = (i-start_index+1);
                }
                i++;
                continue;
            }
            while(map.find(s[i]) !=map.end())
            {
                map.erase(s[start_index]);
                start_index++;
            }
        }
        return max_len;
    }
};