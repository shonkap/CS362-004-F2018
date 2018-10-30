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

    printf("\ntesting adventurer: \t");
  
    initializeGame(2, k, 10, &G);   
    G.whoseTurn = 1;
    G.hand[1][0] = smithy;
    G.deckCount[1] = 5;
    ophandcount = G.deckCount[0];
    endTurn(&G);

    G.whoseTurn = 0;
    G.hand[0][0] = gold;
    G.hand[0][0] = gold;
    G.deckCount[0] = 5;
    handcount = G.deckCount[1];

    int bonus = 1;

    int r = cardEffect(adventurer,1,2,3,&G,0,&bonus);
    assert(handcount+2 == G.handCount[0]);
    assert(deckcount > fullDeckCount(0,0,&G));

    assert(ophandcount == G.handCount[0]);
    assert(opdeckcount == G.deckCount[0]);

    assert(G.hand[0][1] == gold && G.hand[0][2] == gold);
    assert(r == 0);
    //int t4 = ASSERT(r == );

    /*
    if(t1 + t2 + t3 + t4 + t5 + t6 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");  
        */
} 