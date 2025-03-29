#include "tic_tac_toe.h"
#include <iostream>

using namespace std;

int main() {
    TicTacToe game;
    string first_player;
    char play_again;

    do {
        cout << "Enter first player (X or O): ";
        cin >> first_player;
        game.start_game(first_player);

        while (!game.game_over()) {
            int position;
            game.display_board();
            cout << "Player " << game.get_player() << ", enter position (1-9): ";
            cin >> position;
            game.mark_board(position);
        }

        cout << "Game over!" << endl;
        game.display_board();
        game.reset_game();

        cout << "Play again? (y/n): ";
        cin >> play_again;

    } while (play_again == 'y' || play_again == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}