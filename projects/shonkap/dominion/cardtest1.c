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
    G.deckcount[0] = 5;
    handcount = G.deckcount[0];
    endTurn(&G);

    G.whoseTurn = 1;
    G.hand[1][0] = smithy;
    G.deckcount[0] = 5;
    ophandcount = G.deckcount[1];

    int r = cardEffect(smithy,1,2,3 &G,ophandcount,NULL);
    int t1 = ASSERT(ophandcount+2 == G.handcount[1]);
    int t2 = ASSERT(opdeckcount-3 == G.deckcount[1]);

    int t3 = ASSERT(handcount-3 == G.handcount[0]);
    int t4 = ASSERT(deckcount-3 == G.deckcount[0]);

    if(t1 + t2 + t3 + t4 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
}