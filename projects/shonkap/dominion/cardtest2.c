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
    G.deckcount[1] = 5;
    ophandcount = G.deckcount[0];
    endTurn(&G);

    G.whoseTurn = 0;
    G.hand[0][0] = gold;
    G.hand[0][0] = gold;
    G.deckcount[0] = 5;
    handcount = G.deckcount[1];

    int r = cardEffect(adventurer,1,2,3 &G,0,NULL);
    int t1 = ASSERT(handcount+2 == G.handcount[0]);
    int t2 = ASSERT(deckcount > fullDeckCount(0,0,&G));

    int t3 = ASSERT(ophandcount == G.handcount[0]);
    int t4 = ASSERT(opdeckcount == G.deckcount[0]);

    int t5 = ASSERT(G.hand[0][1] == gold && G.hand[0][2] == gold);
    int t6 = ASSERT(r == 0);
    //int t4 = ASSERT(r == );

    if(t1 + t2 + t3 + t4 + t5 + t6 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");   