#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Card played
void wutCard(int card)
{
	switch(card)
	{
		case adventurer:
			printf("Played adventurer card\n");
			break;
		case council_room:
			printf("Played council_room card\n");
			break;
		case feast:
			printf("Played feast card\n");
			break;
		case gardens:
			printf("Played gardens card\n");
			break;
		case mine:
			printf("Played mine card\n");
			break;
		case remodel:
			printf("Played remodel card\n");
			break;
		case smithy:
			printf("Played smithy card\n");
			break;
		case village:
			printf("Played village card\n");
			break;
		case baron:
			printf("Played baron card\n");
			break;
		case great_hall:
			printf("Played great_hall card\n");
			break;
		case minion:
			printf("Played minion card\n");
			break;
		}
}

//Only works on array 10, may change later...
int inArray(int *array, int num)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(array[i]==num)
		{
			return 1;
		}
	}
	return 0;
}

void randomKing(int *cards)
{
	srand(time(NULL));
	int card = 0;
	int temp = 0;
	while(card<10)//We must fill 10 cards
	{
		temp = (int)(8+(rand()%(treasure_map-adventurer)));//These are the king cards
		if(!inArray(cards,temp))//only add one of each cards
		{
			cards[card] = temp;//Look, out cards got added
			card++;//bleh
		}
	}
}

int main (int argc, char** argv)
{
  struct gameState G;
  struct gameState *p = &G;

	//Randomize these
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	//give the new random cards
	randomKing(k);

	printf("%d\n",k);

  printf ("Starting game.\n");
  
	int players = rand()%3 +2;

  initializeGame(players, k, atoi(argv[1]), p);

  int money = 0;
  int smithyPos = -1;
  int adventurerPos = -1;
  int i=0;

  int numSmithies = 0;
  int numAdventurers = 0;

	int actions = 0;
	int who = 0;
	int cardz = 0;
	int fail = 0;
	int buyNum = 0;

	shuffle(who, p);

	while (!isGameOver(p))
	{

		//Action phase! Let's get out money out and all  the possitions filled...
	    money = 0;
	    smithyPos = -1;
	    adventurerPos = -1;
		for (i = 0; i < numHandCards(p); i++)
		{
			if (handCard(i, p) == copper)
				money++;
			else if (handCard(i, p) == silver)
				money += 2;
			else if (handCard(i, p) == gold)
				money += 3;
			else if (handCard(i, p) == smithy)
				smithyPos = i;
			else if (handCard(i, p) == adventurer)
				adventurerPos = i;
		}

		//How many actions we got?
		who = p->whoseTurn;
		actions = 0;
		for(i=0;i<numHandCards(p);i++)
		{
			//Avoid fest, because no...
			if(p->hand[who][i] != feast && p->hand[who][i] >= adventurer && p->hand[who][i] <= treasure_map)
			{
				actions++;
			}
		}

		//Let's use some actions!
		while(actions>0)
		{
			cardz = rand()%numHandCards(p);
			if(playCard(cardz, 0, 0, 0, p))
			{
				wutCard(handCard(cardz, p));
				actions--;
			}
		}

		//Evaluate our wallet!!!!
		money = 0;
		for(i=0; i<numHandCards(p); i++)
		{
			if (handCard(i, p) == copper)
			{
				playCard(i, -1, -1, -1, p);
				money++;
			}else if (handCard(i, p) == silver){
				playCard(i, -1, -1, -1, p);
				money += 2;
			}else if (handCard(i, p) == gold){
				playCard(i, -1, -1, -1, p);
				money += 3;
			}
		}

		//Let's find a card to buy!!!!
		fail = 0;
		while(p->numBuys>0 && fail < 3)//we must buy something
		{
			for(i=0;i<10;i++)
			{
				if(getCost(k[i])<=money)
				{
					cardz = k[i];//if we can't buy the first king card get money
				}
			}
			if(buyCard(cardz, p)==0)
			{
				buyNum++;//king kard!!!
				printf("Player %d bought %d\n",who,cardz);
			}else{
				//money time!
				if(money>=6)
				{
					buyCard(gold,p);
					printf("Player %d bought gold\n",who);
				}else if(money>=3)
				{
					buyCard(silver,p);
					printf("Player %d bought silver\n",who);
				}else{
					buyCard(copper,p);
					printf("Player %d bought copper\n",who);
				}
				fail++;
				cardz++;
			}
		}

	      	endTurn(p);  
		for(i = 0; i<players; i++)
		{
			printf("Player %d: %d\n",i,scoreFor(i,p));
		}    
	}

	printf ("Finished game.\n");
  	for(i = 0; i<players; i++)
	{
		printf("Player %d: %d\n",i,scoreFor(i,p));
	} 

  return 0;
}
