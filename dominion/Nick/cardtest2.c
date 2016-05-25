#include "anassert.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int test, expect;

	expect = state->outpostPlayed+1;

	//Testing outpost
	cardEffect(23,0,0,0,state,0,0);
	test = state->outpostPlayed;

	anassert(test==expect);
	return 0;
}
