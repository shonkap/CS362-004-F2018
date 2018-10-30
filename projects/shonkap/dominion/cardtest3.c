#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1
//gardens

int main () {

    int ophandcount, handcount, opdeckcount, deckcount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState G;

    printf("\ntesting gardens: \t");

    initializeGame(2, k, 10, &G);

    int bonus = 1;
    int r = cardEffect(gardens,1,2,3, &G,0,NULL);

    if(r == -1)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
}