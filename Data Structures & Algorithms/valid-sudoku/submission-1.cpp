class Solution {
private:
    void handleIncrement(uint8_t& i, uint8_t& j, uint8_t& square)
    {
        ++j;
        if (j % 3 == 0)
        {
            ++i;
            j -= 3;
            if (i % 3 == 0 && i > 0)
            {
                ++square;
                if (square % 3 == 0 && square > 0)
                {
                    i = 0;
                    j += 3;
                }
            }
        }
        
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        constexpr uint8_t invalid = std::numeric_limits<uint8_t>::max();
        constexpr uint8_t valid = std::numeric_limits<uint8_t>::min();
        std::vector<std::vector<uint8_t>> horizontal(9, std::vector<uint8_t>(9, invalid));
        std::vector<std::vector<uint8_t>> vertical(9, std::vector<uint8_t>(9, invalid));
        std::vector<std::vector<uint8_t>> squares(9, std::vector<uint8_t>(9, invalid));

        uint8_t i=0, j=0, square=0;
        while (true)
        {
            if (board[i][j] == '.')
            {
                handleIncrement(i, j, square);
                if (square == 9)
                    return true;
                continue;
            }
            if (horizontal[i][board[i][j] - '1'] != invalid)
                return false;
            if (vertical[j][board[i][j] - '1'] != invalid)
                return false;
            if (squares[square][board[i][j] - '1'] != invalid)
                return false;
            
            horizontal[i][board[i][j] - '1'] = valid;
            vertical[j][board[i][j] - '1'] = valid;
            squares[square][board[i][j] - '1'] = valid;

            handleIncrement(i, j, square);
            if (square == 9)
                return true;

        }
    }
};
