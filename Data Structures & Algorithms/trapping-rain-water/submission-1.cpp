class Solution {
public:
    int trap(vector<int>& height) 
    {
        if (height.size() <= 2)
            return 0;

        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int totalVol = 0;

        while (left < right)
        {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);

            if (leftMax > rightMax)
            {
                totalVol += rightMax - height[right];
                --right;
            }
            else
            {
                totalVol += leftMax - height[left];
                ++left;
            }
        }

        return totalVol;
    }
};
