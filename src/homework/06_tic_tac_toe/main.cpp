#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <memory>

int main() {
    TicTacToeManager manager;
    std::unique_ptr<TicTacToe> game;
    std::string first_player;
    int position;
    int game_type;

    std::cout << "Enter 3 for 3x3 or 4 for 4x4 TicTacToe: ";
    std::cin >> game_type;

    if (game_type == 3)
        game = std::make_unique<TicTacToe3>();
    else
        game = std::make_unique<TicTacToe4>();

    std::cout << "Enter first player (X or O): ";
    std::cin >> first_player;
    game->start_game(first_player);

    while (!game->game_over()) {
        std::cout << "Enter position: ";
        std::cin >> position;
        game->mark_board(position);
    }

    manager.save_game(game);
    manager.display_games();

    return 0;
}