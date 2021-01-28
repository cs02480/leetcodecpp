class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int curr = 0;
		int i = 0;
		int max = -222222222;
		while (i<len)
		{
			curr += nums[i];
			if (curr>max)
			{
				max = curr;
			}

			if (curr < 0)
				curr = 0;
			i++;
		}
		return max;
	}
};
