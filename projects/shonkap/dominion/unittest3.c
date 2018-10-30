#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

//whose turn function
int main(){

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  int r = initializeGame(4, k, 10, &G);
  assert(r == 0);

  G.whoseTurn = 0;

  assert(whoseTurn(&G) == 0);

  G.whoseTurn = 1;

  assert(whoseTurn(&G) == 1);
}