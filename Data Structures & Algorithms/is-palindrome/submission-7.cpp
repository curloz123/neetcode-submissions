class Solution {
public:
    bool isPalindrome(std::string& s) {

        int prv = 0;
        int nxt = s.length()-1;
        while (prv < nxt)
        {
            while (prv < nxt && !std::isalnum(static_cast<unsigned char>(s[prv])))
                ++prv;
            while (prv < nxt && !std::isalnum(static_cast<unsigned char>(s[nxt])))
                --nxt;
            if (std::tolower(static_cast<unsigned char>(s[prv])) != std::tolower(static_cast<unsigned char>(s[nxt])))
                return false;

            ++prv;
            --nxt;
        }

        return true;

    }
};
