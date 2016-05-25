#include "dominion.h"
#include "interface.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define MAX_TESTS 100

int main (int argc, char** argv)
{
	struct gameState g;

	int players, seed, fails, deck, hand, test = 0;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("Starting tests.\n");
  
	while(test<MAX_TESTS)
	{
		if(!argc)
			seed = rand();
		else
			seed = 42;
		players = rand() % 4;
		initializeGame(players, k, seed, &g);
		deck = rand() % MAX_DECK;
		hand = rand() % MAX_HAND;
		g.whoseTurn = players;
		g.deckCount[players] = deck;
		g.handCount[players] = hand;
		
		addCardToHand(players, adventurer, &g);

		//decide random cases for testing
		if(rand()%10>5)
		{
			playCard(hand, 0, 0, 0, &g);
			if(g.handCount[players]!=0)
				fails++;
		}else{
			addCardToHand(players, gold, &g);
			addCardToHand(players, gold, &g);
			playCard(hand+2, 0, 0, 0, &g);
			if(g.handCount[players]!=2)
				fails++;
		}

		test++;
	}
	printf ("Test finished with %d fails out of %d tests.\n",fails,test);
	return 0;
}
