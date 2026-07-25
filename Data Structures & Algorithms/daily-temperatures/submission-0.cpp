class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const auto& t = temperatures;
        const auto tSize = t.size();
        if (tSize == 1)
            return {0};

        vector<int> indices = {0};
        vector<int> result(tSize, 0);

        for (int i = 1; i < tSize; ++i)
        {
            while (!indices.empty() && t[i] > t[indices.back()])
            {
                result[indices.back()] = i - indices.back();
                indices.pop_back();
            }

            indices.emplace_back(i);
        }

        return result;
    }
};
