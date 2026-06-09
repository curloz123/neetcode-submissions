class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1)
            return {{strs[0]}};

        unordered_map<string, vector<string>> map;
        for (const auto& str : strs)
        {
            std::vector<int> freq(26, 0);
            for (auto& c : str)
            {
                freq[c - 'a']++;
            }
            std::string ch(freq.begin(), freq.end());
            map[ch].emplace_back(str);
        }
        vector<vector<string>> result;
        for (auto& [s, v] : map)
        {
            result.emplace_back(v);
        }
        return result;
    }
};
