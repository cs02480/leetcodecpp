class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int m=0;
        int j=0;  //Boyer–Moore majority vote algorithm work only when amajorty elem is present 
                    //other wise will give wrong ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(j == 0)
            {
                m=nums[i];
                j=1;
            }
            else
            {
                if(m == nums[i]) ++j;
                else --j;
            }
        }
        //if majorti presnt ans will we in m;
        
        return m;
        
    }
};