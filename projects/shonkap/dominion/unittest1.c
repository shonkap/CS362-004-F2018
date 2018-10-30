#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

//update coins
int main(){
    printf("blah");

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  printf("def didnt make it");
  int r = initializeGame(4, k, 1000, &G);
  printf("didnt make it");
  assert(r == 0);
   G.coins = 0;
   G.hand[0][0] = gold;
   G.hand[0][1] = gold;
   G.hand[0][2] = gold;
   G.hand[0][3] = gold;
   updateCoins(0,&G,0);
   printf("here");

   assert(G.coins == 12);
   G.coins = 0;

   G.hand[0][0] = silver;
   G.hand[0][1] = silver;
   G.hand[0][2] = silver;
   G.hand[0][3] = silver;
   updateCoins(0,&G,0);

   assert(G.coins == 8);
   G.coins = 0;

   G.hand[0][0] = copper;
   G.hand[0][1] = copper;
   G.hand[0][2] = copper;
   G.hand[0][3] = copper;
   updateCoins(0,&G,0);

   assert(G.coins == 4);

   G.hand[0][0] = smithy;
   G.hand[0][1] = smithy;
   G.hand[0][2] = smithy;
   G.hand[0][3] = smithy;
   updateCoins(0,&G,0);

   assert(G.coins == 4);
   

   /*if(t1 + t2 + t3 + t4 == 0)
        printf("test completed successfully! \n");
    else
        printf("test Failed! \n");
        */
printf("test completed successfully! \n");


}