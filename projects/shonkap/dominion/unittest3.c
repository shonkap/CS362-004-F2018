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
  initializeGame(4, k, 1, &G);

  G.whoseTurn = 0;

  int t1 = assert(whoseTurn(G) == 0);

  G.whoseTurn = 1;

  int t2 = assert(whoseTurn(G) == 1);

  if(t1 + t2 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
}