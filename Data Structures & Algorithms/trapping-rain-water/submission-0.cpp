class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int totalArea = 0;

        while (left < right)
        {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);

            if (leftMax > rightMax)
            {
                totalArea += rightMax - height[right];
                --right;
            }
            else 
            {
                totalArea += leftMax - height[left];
                ++left;
            }
        }
        return totalArea;
    }
};
