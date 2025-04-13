#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
public:
    TicTacToe() : pegs(9, " "), player(""), winner("") {}
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const { return player; }
    std::string get_winner() const { return winner; }
    bool game_over();
    void set_next_player();
    void clear_board();
    void display_board() const;

    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

private:
    std::vector<std::string> pegs;
    std::string player;
    std::string winner;
    bool check_board_full() const;
    bool check_column_win() const;
    bool check_diagonal_win() const;
    bool check_row_win() const;
    void set_winner();
};