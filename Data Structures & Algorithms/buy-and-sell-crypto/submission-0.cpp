class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int left = 0;
        for (int right = 0; right < prices.size(); ++right)
        {
            ans = std::max(ans, prices[right] - prices[left]);
            if (prices[right] < prices[left])
                left = right;
        }
        return ans;
    }
};
