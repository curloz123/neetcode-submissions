class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        for (auto c1 : s)
        {
            bool foundIn_t = false;
            for (int i=0; i<t.size(); ++i)
            {
                if (c1 == t[i])
                {
                    std::swap(t[i], t[t.size()-1]);
                    t.pop_back();
                    foundIn_t = true;
                    break;
                }
            }
            if (!foundIn_t)
                return false;
        }
        return true;
    }
};
