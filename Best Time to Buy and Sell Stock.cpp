class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], max = prices[0], res=0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > max) {
                max = prices[i];
                res = std::max(res, max-min);
            }
            else if(prices[i] < min) {
                min = prices[i];
                max = prices[i];
            }
        }
        return res;
    }
};
