class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 2)
        {
            if (nums[0] + nums[1] == target)
            {
                vector<int> result = {0, 1};
                return result;
            }
        }
        std::unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); ++i)
        {
            hash[nums[i]] = i;
        }
        vector<int> result;
        for (int i=0; i<nums.size(); ++i)
        {
            if (hash.find(target - nums[i]) != hash.end() && hash[target - nums[i]] != i)
            {
                result = {i, hash[target-nums[i]]};
                break;
            }
        }
        return result;
    }
};
