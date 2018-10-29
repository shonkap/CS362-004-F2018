#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int main () {

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    struct gameState G;
    struct gameState test;
    struct gameState test1;

    printf("\ntesting Great Hall: \t");

    initializeGame(2, k, 1000, &G);
    initializeGame(2, k, 1000, &test);
    initializeGame(2, k, 1000, &test1);

    cardEffect(great_hall,1,2,3 &test,ophandcount,NULL);

    int t1 = assert(G.handcount[G.whoseTurn]+1 == test.handcount[test.whoseTurn])


    cardEffect(great_hall,1,2,3 &test1,ophandcount,NULL);
    int t2 = assert(G.handcount[G.whoseTurn]+1 == test.handcount[test1.whoseTurn])

    if(t1+t2 == 0 )
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
}