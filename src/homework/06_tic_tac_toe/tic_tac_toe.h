#include <string>
#include <vector>

class TicTacToe {
public:
    TicTacToe() = default;
    TicTacToe(int size);
    void mark_board(int position);
    bool game_over();
    void start_game(std::string first_player);
    void set_next_player();
    void set_winner();
    std::string get_winner() const;
    std::string get_player() const;
    void clear_board();
    const std::vector<std::string>& get_pegs() const;

protected:
    std::vector<std::string> pegs;
    std::string player;
    std::string winner;

    bool check_board_full();
    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
};
