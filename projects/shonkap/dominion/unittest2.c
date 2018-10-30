#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

//supply count
int main(){

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  int r = initializeGame(4, k, 10, &G);
  assert(r == 0);
  G.supplyCount[0] = 10;
  G.supplyCount[2] = 3;
  G.supplyCount[1] = 12;

  assert(supplyCount(0,&G) == 10);
  assert(G.supplyCount[0] == 10);

  assert(supplyCount(3,&G) == 3);
  assert(G.supplyCount[3] == 3);

  assert(supplyCount(2,&G) == 12);
  assert(G.supplyCount[2] == 12);

   /*if(t1 + t2 + t3 + t4 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
        */



}