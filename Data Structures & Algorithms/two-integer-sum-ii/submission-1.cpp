class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        
        while (begin < end)
        {
            while (nums[begin] + nums[end] < target)
                ++begin;
            
            if (nums[begin] + nums[end] == target && begin != end)
                return {begin+1, end+1};
            
            --end;
        }
        return {};
    }
};
