class Solution {
private:
    void productWithOneZero(vector<int>& nums, vector<int>& ans, const int product)
    {
        for (const auto& num : nums)
        {
            if (num == 0)
                ans.emplace_back(product);
            else 
                ans.emplace_back(0);
        }
    }
    void productWithNoZero(vector<int>& nums, vector<int>& ans, const int product)
    {
        for (const auto& num : nums)
        {
            ans.emplace_back(product/num);
        }
    }
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZeroes = 0;
        int totalProduct = 1;

        for (const auto& num : nums)
        {
            if (num == 0)
            {
                numZeroes += 1;
                continue;
            }
            totalProduct *= num;
        }

        if (numZeroes > 1)
        {
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        else if (numZeroes == 1)
        {
            vector<int> ans;
            productWithOneZero(nums, ans, totalProduct);
            return ans;
        }

        vector<int> ans;
        productWithNoZero(nums, ans, totalProduct);
        return ans;

    }
};
