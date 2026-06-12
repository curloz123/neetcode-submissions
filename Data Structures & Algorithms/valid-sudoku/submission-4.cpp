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
        std::array<std::array<bool, 9>, 9> horizontal{};
        std::array<std::array<bool, 9>, 9> vertical{};
        std::array<std::array<bool, 9>, 9> squares{};

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
            if (horizontal[i][board[i][j] - '1'])
                return false;
            if (vertical[j][board[i][j] - '1'])
                return false;
            if (squares[square][board[i][j] - '1'])
                return false;
            
            horizontal[i][board[i][j] - '1'] = true;
            vertical[j][board[i][j] - '1'] = true;
            squares[square][board[i][j] - '1'] = true;

            handleIncrement(i, j, square);
            if (square == 9)
                return true;

        }
    }
};
