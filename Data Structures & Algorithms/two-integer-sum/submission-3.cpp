class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        vector<int> result;

        for (int i=0; i<nums.size(); ++i)
        {
            int other = target - nums[i];
            if (hash.find(other) != hash.end())
            {
                return {hash[other], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
