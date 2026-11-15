class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxVol = 0;

        while (left < right)
        {
            int leftI = heights[left];
            int rightI = heights[right];
            
            if (leftI <= rightI)
            {
                maxVol = std::max(
                    maxVol,
                    (right - left) * leftI
                );
                ++left;
            }
            else
            {
                maxVol = std::max(
                    maxVol,
                    (right - left) * rightI
                );
                --right;
            }
        }
        
        return maxVol;
    }
};
