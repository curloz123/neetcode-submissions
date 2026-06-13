class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return 1;

        int longest = 1;
        int localLongest = 1;
        int localNum = 0;
        std::unordered_set<int> u_set;

        for (const auto& num : nums)
        {
            localNum = num;
            localLongest = 1;
            while (u_set.find(localNum-1) != u_set.end())
            {
                --localNum;
                ++localLongest;
            }
            localNum = num;
            while (u_set.find(localNum+1) != u_set.end())
            {
                ++localNum;
                ++localLongest;
            }

            longest = std::max(longest, localLongest);
            u_set.insert(num);
        }

        return longest;
    }
};
