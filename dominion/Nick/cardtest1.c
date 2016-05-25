#include "anassert.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int test, expect;

	expect = state->handCount[0]+3;

	//Testing smithy
	cardEffect(13,0,0,0,state,0,0);
	test = state->handCount[0];

	anassert(test==expect);

	return 0;
}
