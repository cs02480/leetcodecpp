struct 
{
    bool operator()(int a,int b)
    {
        string num1 = to_string(a)+ to_string(b);
        string num2 = to_string(b)+ to_string(a);
        return num1>num2;
    }
}comp;
class Solution {
    
    
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),comp);
        string ans{};
        for(int i=0;i<nums.size();i++)
        {
            ans+=to_string(nums[i]);
        }
        int len = ans.length();
        int a=0;
        if(len>0 && ans[0] == '0')
            return "0";
        
        return ans;
    }
};



