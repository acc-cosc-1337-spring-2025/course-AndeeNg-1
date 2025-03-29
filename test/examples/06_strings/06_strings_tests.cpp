#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over after 9 moves") {
    TicTacToe game;
    game.start_game("X");

    int moves[] = {1, 2, 3, 4, 5, 7, 6, 9, 8};

    for (int i = 0; i < 9; i++) {
        game.mark_board(moves[i]);
        if (i < 8) {
            REQUIRE(game.game_over() == false);
        }
    }
    REQUIRE(game.game_over() == true);
}