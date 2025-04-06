#include <iostream>
#include <string>
#include "tic_tac_toe.h"

int main()
{
    std::string first_player;
    std::string play_again;

    do
    {
        std::cout << "Welcome to Tic Tac Toe!\n";

        // Ask for first player
        do
        {
            std::cout << "Enter first player (X or O): ";
            std::cin >> first_player;
            if (first_player != "X" && first_player != "O")
            {
                std::cout << "Invalid input. Please enter X or O.\n";
            }
        } while (first_player != "X" && first_player != "O");

        TicTacToe game;
        game.start_game(first_player);

        int position;

        // Game loop
        while (!game.game_over())
        {
            game.display_board();
            std::cout << "Player " << game.get_player() << ", enter position (1-9): ";
            std::cin >> position;

            while (position < 1 || position > 9)
            {
                std::cout << "Invalid position. Choose 1 through 9: ";
                std::cin >> position;
            }

            game.mark_board(position);
        }

        // Show final board + winner
        game.display_board();

        std::string winner = game.get_winner();
        if (winner == "C")
        {
            std::cout << "It's a tie!\n";
        }
        else
        {
            std::cout << "Player " << winner << " wins!\n";
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> play_again;

    } while (play_again == "y" || play_again == "Y");

    std::cout << "Thanks for playing!\n";

    return 0;
}