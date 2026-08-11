class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];

        uint16_t low = 0;
        uint16_t high = nums.size() - 1;
        while (low < high)
        {
            uint16_t mid = (high + low) / 2;
            int16_t midE = nums[mid];

            if (midE < nums[high])
                high = mid;
            else if (midE >= nums[low])
                low = mid + 1;
        }

        return nums[high];
    }
};
