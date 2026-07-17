class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        size_t n1 = s1.size();
        size_t n2 = s2.size();

        std::array<uint32_t, 26> s1_count = {};
        std::array<uint32_t, 26> window = {};
        for (size_t i = 0; i < n1; ++i)
        {
            s1_count[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        uint8_t matches = 0;
        for (size_t i = 0; i < 26; ++i)
        {
            if (s1_count[i] == window[i])
                ++matches;
        }
        if (matches == 26)
            return true;

        for (size_t right = n1; right < n2; ++right)
        {
            auto add = s2[right] - 'a';
            auto rem = s2[right - n1] - 'a';

            ++window[add];
            if (window[add] == s1_count[add])
                ++matches;
            else if (window[add] == s1_count[add] + 1)
                --matches;

            --window[rem];
            if (window[rem] == s1_count[rem])
                ++matches;
            else if (window[rem] == s1_count[rem] - 1)
                --matches;            

            if (matches == 26)
                return true;
        }
        return false;
        
    }
};
