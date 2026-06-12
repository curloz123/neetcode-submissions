class Solution {
private:
    int squareIndex[3][3] = 
    {
        0, 1, 2,
        3, 4, 5,
        6, 7, 8
    };
    inline void getData(uint8_t i, uint8_t j, uint8_t si, uint8_t sj, uint8_t &row, uint8_t &column, uint8_t &square)
    {
        square = squareIndex[si][sj];
        row = 3*si + i;
        column = 3*sj + j;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        std::array<std::array<bool, 9>, 9> horizontal{};
        std::array<std::array<bool, 9>, 9> vertical{};
        std::array<std::array<bool, 9>, 9> squares{};

        uint8_t step = 0;
        uint8_t row, column, square;
        for (; step < 81; ++step)
        {
            uint8_t i = (step / 9) % 3;
            uint8_t j = step % 3;
            uint8_t si = step / 27;
            uint8_t sj = (step % 9) / 3;
            getData(i, j, si, sj, row, column, square);
            
            if (board[row][column] == '.')
                continue; 
                
            int val = board[row][column] - '1';
            if (horizontal[column][val])
                return false;
            if (vertical[row][val])
                return false;
            if (squares[square][val])
                return false;

            horizontal[column][val] = true;
            vertical[row][val] = true;
            squares[square][val] = true;
        }

        return true;

    }
};
