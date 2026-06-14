class Solution {
public:
    bool isPalindrome(std::string& s) {

        std::erase_if(s, [&](unsigned char c){
            return !(std::isalpha(c) || (c >= '0' && c <= '9'));
        });

        uint16_t prv = 0;
        uint16_t nxt = (s.length() == 0) ? 0:s.length()-1;
        while (prv < nxt)
        {
            if (std::tolower(s[prv]) != std::tolower(s[nxt]))
                return false;

            ++prv;
            --nxt;
        }

        return true;

    }
};
