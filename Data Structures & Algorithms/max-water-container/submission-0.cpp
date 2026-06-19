class Solution {
public:
    int maxArea(vector<int>& heights) {
        int begin = 0;
        int end = heights.size() - 1;
        int maxArea = 0;

        while(begin < end)
        {
            int localArea = std::min(heights[begin], heights[end]) *
                                (end - begin);

            maxArea = std::max(maxArea, localArea);

            (heights[begin] > heights[end]) ?
                --end : ++begin;
        }

        return maxArea;
    }
};
