#include <iostream>
#include <string>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

int main() {
    TicTacToeManager manager;
    std::string first_player;
    std::string play_again;

    std::cout << "Welcome to Tic Tac Toe!\n";

    do {
        do {
            std::cout << "\nEnter first player (X or O): ";
            std::cin >> first_player;
            if (first_player != "X" && first_player != "O") {
                std::cout << "Invalid input. Please enter X or O.\n";
            }
        } while (first_player != "X" && first_player != "O");

        TicTacToe game;
        try {
            game.start_game(first_player);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }

        int position;
        bool valid_move = false;

        while (!game.game_over()) {
            std::cout << game;
            std::cout << "Player " << game.get_player() << ", enter position (1-9): ";

            while (!(std::cin >> position)) {
                std::cout << "Invalid input. Please enter a number (1-9): ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            try {
                game.mark_board(position);
                valid_move = true;
            } catch (const std::out_of_range& e) {
                std::cout << "Error: " << e.what() << "\n";
                valid_move = false;
            } catch (const std::runtime_error& e) {
                std::cout << "Error: " << e.what() << "\n";
                valid_move = false;
            }

            if (valid_move) {
                std::cout << game;
            }
        }

        std::cout << game;
        std::string winner = game.get_winner();
        if (winner == "C") {
            std::cout << "It's a tie!\n";
        } else {
            std::cout << "Player " << winner << " wins!\n";
        }

        manager.save_game(game);
        int x_wins, o_wins, ties;
        manager.get_winner_totals(o_wins, x_wins, ties);
        std::cout << "X wins " << x_wins << ", O wins " << o_wins << ", Ties " << ties << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> play_again;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (play_again == "y" || play_again == "Y");

    std::cout << "\nThanks for playing!\n";
    return 0;
}