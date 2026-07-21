class Solution {
public:
    string minWindow(string s, string t) 
    {
        std::unordered_map<char, uint16_t> t_map;
        for (const auto& c : t)
            ++t_map[c];
        
        std::unordered_map<char, uint16_t> window;

        const uint16_t required = t_map.size();
        uint16_t formed = 0;
        uint16_t left = 0;

        std::optional<uint16_t> ans_left;
        std::optional<uint16_t> ans_len;

        for (size_t right = 0; right < s.size(); ++right)
        {
            const auto c = s[right];
            const auto c_count = ++window[c];
            if (t_map.find(c) != t_map.end())
            {
                if (c_count == t_map[c])
                    ++formed;
            }

            for (; left <= right && formed == required; ++left)
            {
                if (!ans_len.has_value())
                {
                    ans_len = (right - left) + 1;
                    ans_left = left;
                }
                else if((right - left) + 1 < ans_len.value())
                {
                    ans_len = (right - left) + 1;
                    ans_left = left;
                }

                const auto c = s[left];
                --window[c];
                if (window[c] < t_map[c])
                    --formed;

            }
        }

        return (ans_len.has_value()) ? s.substr(ans_left.value(), ans_len.value()) : "";
    }
};
