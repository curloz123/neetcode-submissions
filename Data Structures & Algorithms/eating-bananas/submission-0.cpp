class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *std::max_element(piles.begin(), piles.end());
        int low = 1;

        while (low < high)
        {
            int mid = low + ((high - low) / 2);

            int sum = 0;
            for (const int p : piles)
                sum += (p + mid - 1) / mid;

            if (sum <= h)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
