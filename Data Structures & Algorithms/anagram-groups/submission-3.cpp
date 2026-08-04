class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;    

        std::unordered_map<string, vector<string>> uMap;
        for (const auto& str : strs)
        {
            int ascii[26] = {};
            for (const auto ch : str)
            {
                ++ascii[ch - 'a'];
            }
            std::string a(ascii, ascii+26);
            uMap[a].push_back(str);
        }

        for (const auto& [c, v] : uMap)
        {
            result.push_back(v);
        }
        return result;
    }
};
