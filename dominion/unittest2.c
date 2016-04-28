#include "dominion.h"
#include "dominion_helpers.h"
#include "anassert.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int i,a,b = 0;

	for (i = 0; i < state->handCount[0]; i++)
	{
		if (state->hand[0][i] == copper)
		{
			b += 1;
		}
		else if (state->hand[0][i] == silver)
		{
			b += 2;
		}
		else if (state->hand[0][i] == gold)
		{
			b += 3;
		}	
	}

	i = updateCoins(0, state, 0);

	a = state->coins;

	anassert(a==b);
}
