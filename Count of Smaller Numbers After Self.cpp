typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
class Solution {
	vi  count;
	void mergesort(vpi & nums, int lo, int hi)
	{
		if (lo<hi)
		{
			int mid = (lo + hi) / 2;
			mergesort(nums, lo, mid);
			mergesort(nums, mid + 1, hi);
			mymerge(nums, lo, mid, hi);
		}
	}
	void mymerge(vpi & nums, int lo, int mid, int hi)
	{
		vpi ans;

		int i = lo;
		int j = mid + 1;
		int small = 0;
		while (i <= mid && j <= hi)
		{
			if (nums[i].first <= nums[j].first)
			{
				ans.push_back(nums[i]);
				count[nums[i].second] += small;
				i++;
			}
			else
			{
				ans.push_back(nums[j]);
				j++;
				small++;
				/*for (int k = i; k <= mid; k++)
				{
					count[nums[k].second]++;
				}*/
			}
		}
		while (i <= mid)
		{
			count[nums[i].second] += small;
			ans.push_back(nums[i++]);
		}
			
		while (j <= hi)
			ans.push_back(nums[j++]);
		j = lo;
		for (int k = 0; k < ans.size(); k++)
		{
			nums[j] = ans[k];
			j++;
		}
	}
public:
	vector<int> countSmaller(vector<int>& nums) {
		count.resize(nums.size(),0);
		vector<pair<int, int>> copy;
		for (int i = 0; i<nums.size(); i++)
			copy.push_back(make_pair(nums[i], i));
		mergesort(copy, 0, nums.size() - 1);
		return count;
	}
};