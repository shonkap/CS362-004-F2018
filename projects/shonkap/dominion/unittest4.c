#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

//buycard
int main(){

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  int r = initializeGame(4, k, 10, &G);
  
  G.whoseTurn = 0;

  //not enough buys left
  G.numBuys = 0;
  assert(buyCard(3,&G) == -1);

  //test if none left
  G.supplyCount[3] = 0;
  G.numBuys = 3;
  if(buyCard(3,&G) == -1)
    printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
  //check not enough coins
  G.coins = 0;
  G.numBuys = 3;
  if(buyCard(3,&G) == -1)
    printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
  //test to buy card
  G.coins = 20;
  G.numBuys = 3;
  G.supplyCount[3] = 10;
  if(buyCard(3,&G) == 0)
    printf("test completed successfully! \n");
  else
    printf("test Failed! \n");
  if(G.numBuys = 2)
    printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
  if(G.coins = 12)
    printf("test completed successfully! \n");
    else
        printf("test Failed! \n");


   /*if(t1 + t2 + t3 + t4 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
        */



}