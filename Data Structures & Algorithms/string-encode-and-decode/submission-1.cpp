class Solution {
public:

    string encode(const vector<string>& strs) {
        string encoded_string;

        for (auto& str : strs)
        {
            uint8_t string_size = static_cast<uint8_t>(str.size());
            encoded_string += '~';
            encoded_string.append(std::to_string(string_size));
            encoded_string += '~';
            encoded_string.append(str);
        }

        return encoded_string;
    }

    vector<string> decode(const string& s) {
        if (s.size() == 0)
            return {};
        vector<string> decoded_strings;

        //assert(s[0] == '~' && "Invalid encoded string");
        
        int i = 0;        
        while (true)
        {
            string size_asString;
            
            //assert(s[i] == '~' && "Iteratign invalidly");
            ++i;
            while (s[i] != '~')
            {
                size_asString += s[i];
                ++i;
            }
            ++i;
            int size = std::stoi(size_asString);

            string si(s, i, size);
            decoded_strings.emplace_back(si);

            i += size;
            if (i == s.size())
                break;
        }

        return decoded_strings;
    }
};
