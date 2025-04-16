#include "tic_tac_toe.h"
#include <memory>
#include <vector>

class TicTacToeManager {
public:
    void save_game(std::unique_ptr<TicTacToe>& game);
    void get_winner_totals(int& o, int& x, int& t);
    void display_games();

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_wins{0};
    int o_wins{0};
    int ties{0};

    void update_winner_account(std::string winner);
};