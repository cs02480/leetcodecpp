class Solution {
public:
    int maxProfit(vector<int>& price) {
        if(price.size() == 0 || price.size() == 1)
            return 0;
        int len = price.size();
        int i=len;
        int max=0;
        int profit= 0;
        for(i=len-1;i>=0;i--)
        {
            if(profit< max-price[i])
            {
                profit= max-price[i];
            }
            if(max<price[i])
                max = price[i];
        }
        return profit;
    }
};