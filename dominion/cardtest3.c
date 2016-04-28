#include "anassert.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int test, expect;

	expect = state->coins+2;

	//Testing outpost
	cardEffect(18,2,0,0,state,0,0);
	test = state->coins;

	anassert(test==expect);
	return 0;
}
