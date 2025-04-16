#include "tic_tac_toe.h"

class TicTacToe4 : public TicTacToe {
public:
    TicTacToe4();

private:
    bool check_column_win() override;
    bool check_row_win() override;
    bool check_diagonal_win() override;
};
