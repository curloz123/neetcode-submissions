class Solution {
public:
    int maxProfit(vector<int>& prices) {
        uint8_t left = 0;
        int16_t ans = 0;

        for (uint8_t right = 0; right < prices.size(); ++right)
        {
            ans = std::max(ans, (int16_t)(prices[right] - prices[left]));
            if (prices[right] < prices[left])
                left = right;
        }

        return ans;
    }
};
