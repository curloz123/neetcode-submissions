class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return false;
        std::unordered_set<int> sNums;
        for (auto num : nums)
        {
            if (sNums.find(num) != sNums.end())
                return true;
            else
                sNums.insert(num);
        }
        return false;
    }
};