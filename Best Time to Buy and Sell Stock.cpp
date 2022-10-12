class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow=INT_MAX, maxProfit=0, profit=0;
        for(int i=0; i<prices.size(); i++) {
            minTillNow = min(minTillNow, prices[i]);
            profit = prices[i] - minTillNow;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
