class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int leftI = numbers[left];
            int rightI = numbers[right];

            if (leftI + rightI > target)
            {
                --right;
                continue;
            }

            if (leftI + rightI == target)
                return {left+1, right+1};

            ++left; 
        }

        return {0, 1};
    }
};
