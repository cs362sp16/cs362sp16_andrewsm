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

	int players, seed, fails, deck, hand, check, test = 0;

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
		
		addCardToHand(players, embargo, &g);
		check = g.coins;
		playCard(hand, 0, 0, 0, &g);
		if(check+2!=g.coins)
			fails++;

		test++;
	}
	printf ("Test finished with %d fails out of %d tests.\n",fails,test);
	return 0;
}
