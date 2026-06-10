class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> frequencies;
        for (auto &num : nums)
            frequencies[num]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [n, f] : frequencies)
            bucket[f].emplace_back(n);
        
        vector<int> answer;
        for (int i=bucket.size()-1; i >= 0; --i)
        {
            if (bucket[i].size() != 0)
            {
                for (auto x : bucket[i])
                    answer.emplace_back(x);
            }

            if (answer.size() == k)
                return answer; 
        }

        return {};
    }
};
