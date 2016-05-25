#include "anassert.h"

int main()
{
	int i = 0;
	int* k = kingdomCards(0,1,2,3,4,5,6,7,8,9);
	
	for(i = 0; i < 10; i++)
	{
		anassert(k[i] == i);
	}
	return 0;
}
