class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix[0][0] > target || 
            matrix.back().back() < target)
            {
                return false;
            }
        int midC = 0;

        /// finding suspect row
        {
            int left = 0;
            int right = matrix.size() - 1;

            while (left <= right)
            {
                midC = (left + right) / 2;
                int midE = matrix[midC][0];

                if (midE  == target)
                    return true;
                else if (midE < target)
                    left = midC + 1;
                else
                    right = midC - 1;
            }

            midC = right;
        }

        /// finding element in suspected row
        {
            int midR = 0;
            int left = 0;
            int right = matrix[midC].size() - 1;

            while (left <= right)
            {
                midR = (left + right) / 2;
                int midE = matrix[midC][midR];

                if (midE == target)
                    return true;
                else if (midE < target)
                    left = midR + 1;
                else
                    right = midR - 1;
            }
        }

        return false;
    }
};
