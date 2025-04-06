#include <string>
#include <vector>

class TicTacToe
{
public:
    void start_game(std::string first_player);
    void mark_board(int position);
    void display_board() const;
    std::string get_player() const;
    bool game_over();
    std::string get_winner() const;

private:
    void set_next_player();
    void clear_board();
    bool check_board_full() const;
    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;
    void set_winner();

    std::string player;
    std::vector<std::string> pegs{9, " "};
    std::string winner;
};
