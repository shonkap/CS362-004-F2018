#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#include <time.h>
#include <stdlib.h>


#define DEBUG 0
#define NOISY_TEST 1
//smithy

int main () {

    int ophandcount, handcount, opdeckcount, deckcount;

    srand(time(NULL));
    int r;

    int A[20] = {sea_hag,adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall,minion,steward,tribute,ambassador,cutpurse,embargo,outpost,salvager};

    int k[10];

    struct gameState G;

    printf("\ntesting smithy random: \t");

    int i;
    for(i=0; i<3; i++){
        int seed = rand()%1000 + 10;

        int j;
        for(j=0; j<10 ;j++){
            int t = rand()%20 ;
            k[j] = A[t];
        }

        initializeGame(2, k, seed, &G);

        drawCard(0,&G);
        drawCard(0,&G);
        drawCard(0,&G);
        drawCard(0,&G);
        drawCard(0,&G);
        drawCard(0,&G);
        drawCard(0,&G);
        drawCard(0,&G);
        G.whoseTurn = 0;
        G.hand[0][0] = smithy;
        G.deckCount[0] = 5;
        handcount = G.deckCount[0];
        endTurn(&G);

        drawCard(1,&G);
        drawCard(1,&G);
        drawCard(1,&G);
        drawCard(1,&G);
        drawCard(1,&G);
        drawCard(1,&G);
        drawCard(1,&G);
        drawCard(1,&G);
        G.whoseTurn = 1;
        G.hand[1][0] = smithy;
        G.deckCount[0] = 5;
        ophandcount = G.deckCount[1];

        int bonus = 1;

        cardEffect(smithy,1,2,3, &G,ophandcount,&bonus);
        if(ophandcount+2 == G.handCount[1])
            printf("test completed successfully! \n");
        else
            printf("test Failed! \n"); 

        if(opdeckcount-3 == G.deckCount[1])
            printf("test completed successfully! \n");
        else
            printf("test Failed! \n"); 



        if(handcount-3 == G.handCount[0])
            printf("test completed successfully! \n");
        else
            printf("test Failed! \n"); 

        if(deckcount-3 == G.deckCount[0])
            printf("test completed successfully! \n");
        else
            printf("test Failed! \n"); 

        /*
        if(t1 + t2 + t3 + t4 == 0)
            printf("test completed successfully! \n");
        else
            printf("test Failed! \n");
            */
    }
}