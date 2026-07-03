class Solution {
public:
    int characterReplacement(const string &s, const int k) {
        std::array<uint32_t, 26> alpha;
        alpha.fill(0);

        int right = 0;
        int left = 0;
        int longestSubstr = 0;
        int mostFreq = 0;

        for (; right < s.size(); ++right)
        {
            int freq = ++alpha[s[right] - 'A'];
            mostFreq = std::max(mostFreq, freq);
            if ((right - left + 1) - mostFreq <= k)
            {
                longestSubstr = right + 1 - left;
            }
            else
            {
                --alpha[s[left] - 'A'];
                ++left;
            }
        }
        return longestSubstr;
            
    }
};
