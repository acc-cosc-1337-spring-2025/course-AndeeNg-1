#include "tic_tac_toe_manager.h"
#include <iostream>

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_account(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::update_winner_account(std::string winner) {
    if (winner == "X") x_wins++;
    else if (winner == "O") o_wins++;
    else ties++;
}

void TicTacToeManager::get_winner_totals(int& o, int& x, int& t) {
    o = o_wins;
    x = x_wins;
    t = ties;
}

void TicTacToeManager::display_games() {
    for (const auto& game : games) {
        for (const auto& peg : game->get_pegs())
            std::cout << peg << " ";
        std::cout << "\nWinner: " << game->get_winner() << "\n";
    }
}