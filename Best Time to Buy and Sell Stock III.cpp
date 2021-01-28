class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		vector<int>left_price(prices.size(), 0);
		vector<int>right_price(prices.size(), 0);
		int max_profit = 0;
		if (prices.size() != 0)
		{
			int buy = prices.front();
			int prof = 0;
			for (int i = 1; i < len; i++)
			{
				prof = prices[i] - buy;
				left_price[i] = max(left_price[i-1], prof);
				buy = min(prices[i], buy);
			}
		}
		if (prices.size() !=0)
		{
			int cell = prices.back();
			int prof = 0;
			for (int i = len - 2; i >= 0; i--)
			{
				prof = cell - prices[i];
				right_price[i] = max(right_price[i + 1], prof);
				cell = max(prices[i], cell);

			}
		}
		if (!prices.empty())
		{
			max_profit = left_price.back();
		}

		for (int i = 1; i < len; i++)
		{
			int sum = left_price[i - 1] + right_price[i];
			max_profit = max(max_profit, sum);
		}
		return max_profit;
	}
};