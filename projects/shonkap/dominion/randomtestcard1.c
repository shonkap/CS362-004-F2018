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
//gardens

int main () {
    srand(time(NULL));
    int r;

    int A[20] = {sea_hag,adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall,minion,steward,tribute,ambassador,cutpurse,embargo,outpost,salvager};

    int k[10];

    struct gameState G;

    printf("\ntesting gardens random: \t");

    int i;
    for(i=0; i<3; i++){

        int j;
        for(j=0; j<10 ;j++){
            int t = rand()%20 ;
            k[j] = A[t];
        }

        initializeGame(2, k, 10, &G);

        r = cardgardens();

        if(r == -1)
            printf("test completed successfully! \n");
        else
            printf("test Failed! \n");
    }
}