#include "dominion.h"
#include "dominion_helpers.h"

void unitTest1(struct gameState *state,int smithyPos)
{
	int test, expect;

	expect = state->outpostPlayed+1;

	//Testing outpost
	cardEffect(23,0,0,0,state,smithyPos,int* 0);
	test = state->outpostPlayed;

	assert(test==expect);
}
