class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0 || prices.size() == 1)return 0;
		int len = prices.size();
		int i = 0;
		int profit = 0;
		int min, max;
		while (i < len - 1)
		{
			while (i < len - 1 && prices[i] >= prices[i + 1])i++;
			min = prices[i];
			while (i < len - 1 && prices[i] <= prices[i + 1]) i++;
			max = prices[i];
			profit += max - min;

		}
		return profit;

	}
};
