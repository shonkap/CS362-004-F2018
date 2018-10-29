#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int main () {

    int ophandcount, handcount, opdeckcount, deckcount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf("\ntesting gardens: \t");

    initializeGame(2, k, 10, &G);

    int r = cardEffect(gardens,1,2,3 &G,ophandcount,NULL);

    int t1 = assert(r == -1);

    if(t1 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
}