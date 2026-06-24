class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        std::unordered_set<char> uSet;

        int left = 0;
        int largest = 0;
        int localLargest = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            if (uSet.find(s[right]) != uSet.end())
            {
                largest = std::max(largest, localLargest);
                while(s[left] != s[right])
                {
                    uSet.erase(s[left]);
                    ++left;
                    --localLargest;
                }
                ++left;
                continue;
            }

            uSet.insert(s[right]);
            ++localLargest;
        }
        return std::max(largest, localLargest);
    }
};
