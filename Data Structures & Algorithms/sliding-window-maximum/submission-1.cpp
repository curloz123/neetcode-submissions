class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == k)
            return {std::ranges::max(nums)};


        std::vector<int> max;
        int prevMax = nums[0];
        int prevMaxIndex = 0;
        const auto numsLength = nums.size();

        auto calcNewMax = [&](int start, int end)
        {
            auto localMax = nums[start];
            auto localMaxIndex = start;
            for (int i = start; i <= end; ++i)
            {
                if (nums[i] > localMax)
                {
                    localMax = nums[i];
                    localMaxIndex = i;
                }
            }

            prevMax = localMax;
            prevMaxIndex = localMaxIndex;
        };
        calcNewMax(0, k-1);
        max.emplace_back(prevMax);

        int left = 0;
        int right = k - 1;
        while (left < (numsLength - k))
        {
            if (prevMaxIndex == left)
            {
                calcNewMax(left+1, right+1);
            }
            ++left; 

            if (nums[right + 1] > prevMax)
            {
                prevMax = nums[right + 1];
                prevMaxIndex = right + 1;
            }
            ++right;

            max.emplace_back(prevMax);
        }

        return max;
    }
};
