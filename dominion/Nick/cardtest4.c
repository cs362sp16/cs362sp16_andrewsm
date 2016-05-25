#include "anassert.h"
#include "dominion.h"
#include "dominion_helpers.h"

int main()
{
	struct gameState* state = calloc(1, sizeof(struct gameState));
	int test, expect;

	expect = scoreFor(0, state);
	//Testing garden (test winners???)
	cardEffect(10,2,0,0,state,0,0);
	test = scoreFor(0, state);

	anassert(test>=expect);
	return 0;
}
