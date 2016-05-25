void unitTest5()
{
	int cardNumber = 4;
	int value = 0;		

	switch( cardNumber ) 
	{
		case curse:
			value = 0;
		case estate:
			value = 2;
		case duchy:
			value = 5;
		case province:
			value = 8;
		case copper:
			value = 0;
		case silver:
			value = 3;
		case gold:
			value = 6;
		case adventurer:
			value = 6;
		case council_room:
			value = 5;
		case feast:
			value = 4;
		case gardens:
			value = 4;
		case mine:
			value = 5;
		case remodel:
			value = 4;
		case smithy:
			value = 4;
		case village:
			value = 3;
		case baron:
			value = 4;
		case great_hall:
			value = 3;
		case minion:
			value = 5;
		case steward:
			value = 3;
		case tribute:
			value = 5;
		case ambassador:
			value = 3;
		case cutpurse:
			value = 4;
		case embargo: 
			value = 2;
		case outpost:
			value = 5;
		case salvager:
			value = 4;
		case sea_hag:
			value = 4;
		case treasure_map:
			value = 4;
		}
		value = -1;
	}

	cardNumber = getCost(cardNumber);

	assert(value==cardNumber);
}
