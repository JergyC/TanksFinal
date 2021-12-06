#include "Tanks.h"
#pragma warning(disable : 4996)

int pocethracu;
int vybermapy;
char Map[MAX_Y][MAX_X];
int playersPositions[MAX_PLAYERS][2];



void playersDeclaration()
{

	printf_s("\nVitejte ve hre tanky!");

	char hrac1[31], hrac2[31], hrac3[31], hrac4[31], hrac5[31];
a:
	printf_s("\nZadejte pocet hracu (maximum je 5): ");
	scanf_s("%d", &pocethracu);
	if (pocethracu > 1 && pocethracu < 6)
	{
		switch (pocethracu)
		{
		case 2:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &hrac1);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &hrac2);
			addPlayersToMap('A', Map, playersPositions);
			addPlayersToMap('B', Map, playersPositions);
			break;
		}
		case 3:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &hrac1);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &hrac2);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &hrac3);
			addPlayersToMap('A', Map, playersPositions);
			addPlayersToMap('B', Map, playersPositions);
			addPlayersToMap('C', Map, playersPositions);
			break;
		}
		case 4:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &hrac1);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &hrac2);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &hrac3);
			printf_s("\nZadejte jmeno ctvrteho hrace: ");
			scanf("%30s", &hrac4);
			addPlayersToMap('A', Map, playersPositions);
			addPlayersToMap('B', Map, playersPositions);
			addPlayersToMap('C', Map, playersPositions);
			addPlayersToMap('D', Map, playersPositions);
			break;
		}
		case 5:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &hrac1);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &hrac2);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &hrac3);
			printf_s("\nZadejte jmeno ctvrteho hrace: ");
			scanf("%30s", &hrac4);
			printf_s("\nZadejte jmeno pateho hrace: ");
			scanf("%30s", &hrac5);
			addPlayersToMap('A', Map, playersPositions);
			addPlayersToMap('B', Map, playersPositions);
			addPlayersToMap('C', Map, playersPositions);
			addPlayersToMap('D', Map, playersPositions);
			addPlayersToMap('E', Map, playersPositions);
			break;
		}

		}

	}
	else if (pocethracu == 1)
	{
		printf_s("Jeden hrac je malo!");
		goto a;
	}
	else
	{
		printf_s("Neplatna volba!");
		goto a;
	}

}



int main() {
	srand(time(NULL));
	nadpis();
	mapChoice(vybermapy);
	loadMap(Map);
	playersDeclaration();
	printMap(Map);
	destroyPlayer(playersPositions[0][0], playersPositions[0][1], Map);
	printMap(Map);
	//souradnice(4, 15, 60, 1, Map);
}
