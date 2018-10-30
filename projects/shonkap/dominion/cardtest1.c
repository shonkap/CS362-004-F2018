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

    printf("\ntesting smithy: \t");
  
    initializeGame(2, k, 10, &G);   
    G.whoseTurn = 0;
    G.hand[0][0] = smithy;
    G.deckCount[0] = 5;
    handcount = G.deckCount[0];
    endTurn(&G);

    G.whoseTurn = 1;
    G.hand[1][0] = smithy;
    G.deckCount[0] = 5;
    ophandcount = G.deckCount[1];

    int bonus = 1;

    cardEffect(smithy,1,2,3, &G,ophandcount,&bonus);
    assert(ophandcount+2 == G.handCount[1]);
    assert(opdeckcount-3 == G.deckCount[1]);

    assert(handcount-3 == G.handCount[0]);
    assert(deckcount-3 == G.deckCount[0]);

    /*
    if(t1 + t2 + t3 + t4 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
        */
}