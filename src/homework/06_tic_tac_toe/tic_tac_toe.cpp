#include "tic_tac_toe.h"

bool TicTacToe::game_over() {
    return check_board_full();
}

void TicTacToe::start_game(string first_player) {
    if (first_player == "X" || first_player == "O") {
        player = first_player;
        clear_board();
    } else {
        cout << "Invalid first player. Use 'X' or 'O'." << endl;
    }
}

void TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= 9 && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        set_next_player();
    } else {
        cout << "Invalid position. Try again!" << endl;
    }
}

string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    for (int i = 0; i < 9; i += 3) {
        cout << " " << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << " " << endl;
        if (i < 6) cout << "---|---|---" << endl;
    }
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const auto &peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

void TicTacToe::reset_game() {
    clear_board();
}

void TicTacToe::clear_board() {
    pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
}