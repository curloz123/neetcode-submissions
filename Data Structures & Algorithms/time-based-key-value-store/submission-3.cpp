class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> dict;
public:
    TimeMap() {
        dict.clear();
    }
   
    void set(string key, string value, int timestamp) {
        dict[key].emplace_back(timestamp, std::move(value));
    }
    
    string get(string key, int timestamp) {
        auto k = dict.find(key);
        if (k == dict.end())
            return "";

        const auto& v = k->second;
        int right = v.size() - 1;
        int left = 0;

        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            const auto& midE = v[mid];

            if (midE.first == timestamp)
            {
                return midE.second;
            }
            else if (timestamp < midE.first)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (right == -1)
            return "";
        
        return v[right].second;
    }
};