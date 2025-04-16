#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tic_tac_toe_4.h"
#include <memory>

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test win by first row 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);  // X
    game->mark_board(5);  // O
    game->mark_board(2);  // X
    game->mark_board(6);  // O
    game->mark_board(3);  // X
    game->mark_board(7);  // O
    game->mark_board(4);  // X
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win by first column 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("O");
    game->mark_board(1);  // O
    game->mark_board(2);  // X
    game->mark_board(5);  // O
    game->mark_board(3);  // X
    game->mark_board(9);  // O
    game->mark_board(4);  // X
    game->mark_board(13); // O
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test win diagonally from top left 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);   // X
    game->mark_board(2);   // O
    game->mark_board(6);   // X
    game->mark_board(3);   // O
    game->mark_board(11);  // X
    game->mark_board(4);   // O
    game->mark_board(16);  // X
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test win diagonally from top right 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("O");
    game->mark_board(4);   // O
    game->mark_board(1);   // X
    game->mark_board(7);   // O
    game->mark_board(2);   // X
    game->mark_board(10);  // O
    game->mark_board(3);   // X
    game->mark_board(13);  // O
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test tie game 4", "[TicTacToe4]") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);  // X
    game->mark_board(2);  // O
    game->mark_board(3);  // X
    game->mark_board(4);  // O
    game->mark_board(5);  // X
    game->mark_board(6);  // O
    game->mark_board(7);  // X
    game->mark_board(8);  // O
    game->mark_board(9);  // X
    game->mark_board(10); // O
    game->mark_board(11); // X
    game->mark_board(12); // O
    game->mark_board(13); // X
    game->mark_board(14); // O
    game->mark_board(15); // X
    game->mark_board(16); // O
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "C");
}