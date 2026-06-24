class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        std::unordered_set<char> uSet;

        int left = 0;
        int largest = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            while (uSet.find(s[right]) != uSet.end())
            {
                uSet.erase(s[left]);
                ++left;
            }

            uSet.insert(s[right]);
            largest = std::max(largest, right - left + 1);
        }
        return largest;
    }
};
