#include "dominion.h"
#include "dominion_helpers.h"
#include "anassert.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int test = 0;
	int i;
	int score = 0;
	//score from hand
	for (i = 0; i < state->handCount[0]; i++)
	{
		if (state->hand[0][i] == curse) { score = score - 1; };
		if (state->hand[0][i] == estate) { score = score + 1; };
		if (state->hand[0][i] == duchy) { score = score + 3; };
		if (state->hand[0][i] == province) { score = score + 6; };
		if (state->hand[0][i] == great_hall) { score = score + 1; };
		if (state->hand[0][i] == gardens) { score = score + ( fullDeckCount(0, 0, state) / 10 ); };
	}

	//score from discard
	for (i = 0; i < state->discardCount[0]; i++)
	{
		if (state->discard[0][i] == curse) { score = score - 1; };
		if (state->discard[0][i] == estate) { score = score + 1; };
		if (state->discard[0][i] == duchy) { score = score + 3; };
		if (state->discard[0][i] == province) { score = score + 6; };
		if (state->discard[0][i] == great_hall) { score = score + 1; };
		if (state->discard[0][i] == gardens) { score = score + ( fullDeckCount(0, 0, state) / 10 ); };
	}

	//score from deck
	for (i = 0; i < state->deckCount[0]; i++)
	{
		if (state->deck[0][i] == curse) { score = score - 1; };
		if (state->deck[0][i] == estate) { score = score + 1; };
		if (state->deck[0][i] == duchy) { score = score + 3; };
		if (state->deck[0][i] == province) { score = score + 6; };
		if (state->deck[0][i] == great_hall) { score = score + 1; };
		if (state->deck[0][i] == gardens) { score = score + ( fullDeckCount(0, 0, state) / 10 ); };
	}

	test = scoreFor (0, state);
	anassert(test==score);
}
