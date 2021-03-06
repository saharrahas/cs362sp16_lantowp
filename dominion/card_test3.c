#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int my_assert(int passed, char *message) {
  //Test failed
  if (passed == 0) {
    printf("FAIL\n");
    return 1;
  }

  //Test passed
  return 0;
}

int main (int argc, char** argv) {
  struct gameState game_state_1;
  struct gameState game_state_2;
  struct gameState game_state_3;
  int num_of_players = 2;
  int cards[10] = {steward, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
  int initial_num_cards;
  int initial_num_coin;

  //Initial Games
  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state_1);
  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state_2);
  initializeGame(num_of_players, cards, atoi(argv[1]), &game_state_3);

  //Test for choice 1
  initial_num_cards = numHandCards(&game_state_1);
  cardEffect(steward, 1, 0, 0, &game_state_1, 0, 0);
  if (my_assert(numHandCards(&game_state_1) == initial_num_cards + 1,
  "Steward drew the wrong number of cards\n")) {
    return 0;
  }

  //Test for choice 2
  initial_num_coin = game_state_2.coins;
  cardEffect(steward, 2, 0, 0, &game_state_2, 0, 0);
  if (my_assert(game_state_2.coins == initial_num_coin + 2,
  "Steward added an incorrect number of coins\n")) {
    return 0;
  }

  //Test for choice 3
  initial_num_cards = numHandCards(&game_state_3);
  cardEffect(steward, 3, 1, 2, &game_state_3, 0, 0);
  if (my_assert(numHandCards(&game_state_3) == initial_num_cards - 3,
  "Steward discarded the wrong number of cards\n")) {
    return 0;
  }

  printf ("PASS\n");

  return 0;
}
