#include "Tanks.h"
#pragma warning(disable : 4996)

int pocethracu;
int vybermapy;
char Map[MAX_Y][MAX_X];
int playersPositions[MAX_PLAYERS][2];
char destroyedPlayer;

Players A;


void playersDeclaration()
{
	A.A.tank = 'A';
	A.B.tank = 'B';
	A.C.tank = 'C';
	A.D.tank = 'D';
	A.E.tank = 'E';

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
			scanf("%30s", &A.A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &A.B.meno);
			addPlayersToMap(A.A.tank, Map, A.A.position);
			addPlayersToMap(A.B.tank, Map, A.B.position);
			break;
		}
		case 3:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &A.A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &A.B.meno);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &A.C.meno);
			addPlayersToMap(A.A.tank, Map, A.A.position);
			addPlayersToMap(A.B.tank, Map, A.B.position);
			addPlayersToMap(A.C.tank, Map, A.C.position);
			break;
		}
		case 4:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &A.A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &A.B.meno);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &A.C.meno);
			printf_s("\nZadejte jmeno ctvrteho hrace: ");
			scanf("%30s", &A.D.meno);
			addPlayersToMap(A.A.tank, Map, A.A.position);
			addPlayersToMap(A.B.tank, Map, A.B.position);
			addPlayersToMap(A.C.tank, Map, A.C.position);
			addPlayersToMap(A.D.tank, Map, A.D.position);
			break;
		}
		case 5:
		{
			printf_s("\nZadejte jmeno prvniho hrace: ");
			scanf("%30s", &A.A.meno);
			printf_s("\nZadejte jmeno druheho hrace: ");
			scanf("%30s", &A.B.meno);
			printf_s("\nZadejte jmeno tretiho hrace: ");
			scanf("%30s", &A.C.meno);
			printf_s("\nZadejte jmeno ctvrteho hrace: ");
			scanf("%30s", &A.D.meno);
			printf_s("\nZadejte jmeno pateho hrace: ");
			scanf("%30s", &A.E.meno);
			addPlayersToMap(A.A.tank, Map, A.A.position);
			addPlayersToMap(A.B.tank, Map, A.B.position);
			addPlayersToMap(A.C.tank, Map, A.C.position);
			addPlayersToMap(A.D.tank, Map, A.D.position);
			addPlayersToMap(A.E.tank, Map, A.E.position);
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
	destroyPlayer(A.A.position[0][0], A.A.position[0][1], Map);
	printMap(Map);
	//souradnice(4, 15, 60, 1, Map);
}
