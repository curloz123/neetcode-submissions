class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        std::vector<int> frequency(26, 0);
        for (const auto c1 : s)
            ++frequency[c1 - 'a'];
        for (const auto c2 : t)
            --frequency[c2 - 'a'];
        
        for (auto i : frequency)
            if (i != 0) return false;

        return true;
    }
};
