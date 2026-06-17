class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        const int size = nums.size();
        std::unordered_set<int> seen;

        for(int begin = 0; begin < (size - 2); ++begin)
        {
            if (seen.find(nums[begin]) != seen.end())
                continue;
            
            seen.insert(nums[begin]);
            const int target = -(nums[begin]);
            std::unordered_set<int> uSet;

            for (int i=begin+1; i<size; ++i)
            {
                if (auto it = uSet.find(target - nums[i]); it != uSet.end())
                {
                    result.push_back({nums[begin], *it, nums[i]});

                    while (i + 1 < size && nums[i] == nums[i + 1]) {
                        ++i;
                    }
                    continue;
                }
                uSet.insert(nums[i]);
            }
        }
        
        return result;
    }
};
