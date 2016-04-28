#include "dominion.h"
#include "dominion_helpers.h"
#include "anassert.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int i;
	int count = 0;
	int test;

	for (i = 0; i < state->deckCount[0]; i++)
	{
		if (state->deck[0][i] == 0) count++;
	}

	for (i = 0; i < state->handCount[0]; i++)
	{
		if (state->hand[0][i] == 0) count++;
	}

	for (i = 0; i < state->discardCount[0]; i++)
	{
		if (state->discard[0][i] == 0) count++;
	}

	test = fullDeckCount(0,0,state);

	anassert(test==count);
}
