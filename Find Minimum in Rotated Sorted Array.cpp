class Solution {
    int findpivot(vector<int>& nums,int lo,int hi)
    {
        if (hi < lo) 
         return -1; 
          if (hi == lo) 
             return lo; 
        
            int mid = (lo+hi)/2;
            
            if(mid < hi && nums[mid]>nums[mid+1])
                return mid;
            else if(mid>lo && nums[mid]<nums[mid-1])
                return mid-1;
            else if(nums[lo] >= nums[mid])
                return findpivot(nums,lo,mid-1);
            
            return findpivot(nums,mid+1,hi);
        
    }
public:
    int findMin(vector<int>& nums) {
        
        int piv = findpivot(nums, 0, nums.size() - 1);

		if (piv == -1)return nums[0];

		return nums[(piv + 1) % nums.size()];
    }
};