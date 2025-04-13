#include "tic_tac_toe.h"
#include <stdexcept>

void TicTacToe::start_game(std::string first_player) {
    if (first_player != "X" && first_player != "O") {
        throw std::invalid_argument("First player must be 'X' or 'O'.");
    }
    player = first_player;
    winner.clear();
    clear_board();
}

void TicTacToe::mark_board(int position) {
    if (position < 1 || position > 9) {
        throw std::out_of_range("Position must be between 1 and 9.");
    }
    if (pegs[position - 1] != " ") {
        throw std::runtime_error("Position already occupied.");
    }
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const {
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << (pegs[i] == " " ? std::to_string(i + 1) : pegs[i]) << " | "
                  << (pegs[i + 1] == " " ? std::to_string(i + 2) : pegs[i + 1]) << " | "
                  << (pegs[i + 2] == " " ? std::to_string(i + 3) : pegs[i + 2]) << "\n";
        if (i < 6) {
            std::cout << "---+---+---\n";
        }
    }
    std::cout << "\n";
}

bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

void TicTacToe::clear_board() {
    pegs.assign(9, " ");
}

bool TicTacToe::check_board_full() const {
    return std::all_of(pegs.begin(), pegs.end(), [](const std::string& peg) {
        return peg != " ";
    });
}

bool TicTacToe::check_row_win() const {
    for (int i = 0; i <= 6; i += 3) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_column_win() const {
    for (int i = 0; i < 3; ++i) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win() const {
    return (pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) ||
           (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]);
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    out << "\n";
    for (int i = 0; i < 9; i += 3) {
        out << " " << (game.pegs[i] == " " ? std::to_string(i + 1) : game.pegs[i]) << " | "
            << (game.pegs[i + 1] == " " ? std::to_string(i + 2) : game.pegs[i + 1]) << " | "
            << (game.pegs[i + 2] == " " ? std::to_string(i + 3) : game.pegs[i + 2]) << "\n";
        if (i < 6) {
            out << "---+---+---\n";
        }
    }
    out << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
    game.clear_board();
    std::string input;
    for (int i = 0; i < 9; ++i) {
        in >> input;
        if (input == "X" || input == "O") {
            game.pegs[i] = input;
        } else {
            game.pegs[i] = " ";
        }
    }
    in >> game.player;
    if (game.player != "X" && game.player != "O") {
        game.player = "X";
    }
    return in;
}