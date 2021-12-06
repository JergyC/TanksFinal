#include "Tanks.h"
#pragma warning(disable : 4996)

int pocethracu;
int vybermapy;
char Map[MAX_Y][MAX_X];
int playersPositions[MAX_PLAYERS][2];

Player A, B, C, D, E;



void playersDeclaration()
{
	A.tank = 'A';
	B.tank = 'B';
	C.tank = 'C';
	D.tank = 'D';
	E.tank = 'E';
	printf_s("\nVitejte ve hre tanky!");

	//char hrac1[31], hrac2[31], hrac3[31], hrac4[31], hrac5[31];
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
			scanf("%30s", &A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &B.meno);
			addPlayersToMap(A.tank, Map, A.position);
			addPlayersToMap(B.tank, Map, B.position);
			break;
		}
		case 3:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &B.meno);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &C.meno);
			addPlayersToMap(A.tank, Map, A.position);
			addPlayersToMap(B.tank, Map, B.position);
			addPlayersToMap(C.tank, Map, C.position);
			break;
		}
		case 4:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &B.meno);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &C.meno);
			printf_s("\nZadejte jmeno ctvrteho hrace: ");
			scanf("%30s", &D.meno);
			addPlayersToMap(A.tank, Map, A.position);
			addPlayersToMap(B.tank, Map, B.position);
			addPlayersToMap(C.tank, Map, C.position);
			addPlayersToMap(D.tank, Map, D.position);
			break;
		}
		case 5:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &B.meno);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &C.meno);
			printf_s("\nZadejte jmeno ctvrteho hrace: ");
			scanf("%30s", &D.meno);
			printf_s("\nZadejte jmeno pateho hrace: ");
			scanf("%30s", &E.meno);
			addPlayersToMap(A.tank, Map, A.position);
			addPlayersToMap(B.tank, Map, B.position);
			addPlayersToMap(C.tank, Map, C.position);
			addPlayersToMap(D.tank, Map, D.position);
			addPlayersToMap(E.tank, Map, E.position);
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
	destroyPlayer(A.position[0][0], A.position[0][1], Map);
	printMap(Map);
	//souradnice(4, 15, 60, 1, Map);
}
