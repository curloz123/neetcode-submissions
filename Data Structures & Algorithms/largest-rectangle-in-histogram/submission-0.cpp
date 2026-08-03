class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        std::stack<int> indexSt;
        int maxArea = 0;
        const int heightsSize = heights.size();
        for (int i = 0; i <= heightsSize; ++i)
        {
            int currHeight = (i == heightsSize) ? 0 : heights[i];

            while (!indexSt.empty() && heights[indexSt.top()] > currHeight)
            {
                int height = heights[indexSt.top()];
                indexSt.pop();

                int width = (indexSt.empty()) ? 
                    (i) :  
                    (i - indexSt.top() - 1);

                maxArea = std::max(maxArea, height * width);
            }

            indexSt.push(i);
        }

        return maxArea;
    }
};
