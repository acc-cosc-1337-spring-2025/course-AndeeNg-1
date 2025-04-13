#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test invalid first player throws exception") {
    TicTacToe game;
    REQUIRE_THROWS_AS(game.start_game("Z"), std::invalid_argument);
}

TEST_CASE("Test mark_board with invalid position throws exception") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE_THROWS_AS(game.mark_board(0), std::out_of_range);
    REQUIRE_THROWS_AS(game.mark_board(10), std::out_of_range);
}

TEST_CASE("Test mark_board on occupied position throws exception") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1);
    REQUIRE_THROWS_AS(game.mark_board(1), std::runtime_error);
}

TEST_CASE("Test game over with a tie (9 slots filled)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(6);
    game.mark_board(8);
    game.mark_board(7);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column (X wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column (O wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(3);
    game.mark_board(8);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test win by third column (X wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3);
    game.mark_board(1);
    game.mark_board(6);
    game.mark_board(2);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row (X wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row (O wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(7);
    game.mark_board(6);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test win by third row (X wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7);
    game.mark_board(1);
    game.mark_board(8);
    game.mark_board(2);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left (X wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(3);
    game.mark_board(9);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left (O wins)") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(7);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(3);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("Test TicTacToeManager winner totals") {
    TicTacToeManager manager;
    TicTacToe game;

    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(5);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
    manager.save_game(game);

    game.start_game("X");
    game.mark_board(1);
    game.mark_board(4);
    game.mark_board(2);
    game.mark_board(5);
    game.mark_board(7);
    game.mark_board(6);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
    manager.save_game(game);

    game.start_game("X");
    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(3);
    game.mark_board(5);
    game.mark_board(4);
    game.mark_board(6);
    game.mark_board(8);
    game.mark_board(7);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
    manager.save_game(game);

    int x_wins, o_wins, ties;
    manager.get_winner_totals(o_wins, x_wins, ties);
    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}