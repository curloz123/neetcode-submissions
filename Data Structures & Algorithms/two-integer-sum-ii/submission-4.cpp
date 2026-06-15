class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        
        while (begin < end)
        {
            int sum = nums[begin] + nums[end];
            if (sum == target)
                return {begin + 1, end + 1};
            else if (sum < target)
                ++begin;
            else 
                --end;
        }
        return {};
    }
};
