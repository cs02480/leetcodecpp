class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if(map.find(target - nums[i]) != map.end())
            {
                return vector<int>{map[target - nums[i]],i};
            }
            
            map[nums[i]] = i;
        }
        return vector<int>{-1,-1};
    }
};