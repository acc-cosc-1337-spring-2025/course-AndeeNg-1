#include "tic_tac_toe.h"

TicTacToe::TicTacToe(int size) : pegs(size * size, " ") {}

const std::vector<std::string>& TicTacToe::get_pegs() const {
    return pegs;
}

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::clear_board() {
    std::fill(pegs.begin(), pegs.end(), " ");
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::game_over() {
    if (check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs)
        if (peg == " ")
            return false;
    return true;
}

bool TicTacToe::check_column_win() { return false; }
bool TicTacToe::check_row_win() { return false; }
bool TicTacToe::check_diagonal_win() { return false; }

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

std::string TicTacToe::get_winner() const { return winner; }
std::string TicTacToe::get_player() const { return player; }