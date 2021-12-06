#include "Tanks.h"
#pragma warning(disable : 4996)

int pocethracu;
int vybermapy;
char Map[MAX_Y][MAX_X];
char DefMap[MAX_Y][MAX_X];
int uhol;

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
			A.A.life = 1;
			addPlayersToMap(A.B.tank, Map, A.B.position);
			A.B.life = 1;
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
			A.A.life = 1;
			addPlayersToMap(A.B.tank, Map, A.B.position);
			A.B.life = 1;
			addPlayersToMap(A.C.tank, Map, A.C.position);
			A.C.life = 1;
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
			A.A.life = 1;
			addPlayersToMap(A.B.tank, Map, A.B.position);
			A.B.life = 1;
			addPlayersToMap(A.C.tank, Map, A.C.position);
			A.C.life = 1;
			addPlayersToMap(A.D.tank, Map, A.D.position);
			A.D.life = 1;
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
			A.A.life = 1;
			addPlayersToMap(A.B.tank, Map, A.B.position);
			A.B.life = 1;
			addPlayersToMap(A.C.tank, Map, A.C.position);
			A.C.life = 1;
			addPlayersToMap(A.D.tank, Map, A.D.position);
			A.D.life = 1;
			addPlayersToMap(A.E.tank, Map, A.E.position);
			A.E.life = 1;
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
void gameCycle() {
	printMap(Map);
	loadToDef(Map, DefMap);
	while (pocethracu > 1) {
		if (A.A.life == 1) {
			printf("%s, zadaj uhol strelby: ", A.A.meno);
			scanf_s("%d", &uhol);
			souradnice(A.A.position[0][0], A.A.position[0][1], uhol, VELOCITY, Map, A, pocethracu);
			printMap(Map);
			loadToDef(DefMap, Map);

		}
		if (A.B.life == 1) {
			printf("%s, zadaj uhol strelby: ", A.B.meno);
			scanf_s("%d", &uhol);
			souradnice(A.B.position[0][0], A.B.position[0][1], uhol, VELOCITY, Map, A, pocethracu);
			printMap(Map);
			loadToDef(DefMap, Map);
		}
		if (A.C.life == 1) {
			printf("%s, zadaj uhol strelby: ", A.C.meno);
			scanf_s("%d", &uhol);
			souradnice(A.C.position[0][0], A.C.position[0][1], uhol, VELOCITY, Map, A, pocethracu);
			printMap(Map);
			loadToDef(DefMap, Map);
		}
		if (A.D.life == 1) {
			printf("%s, zadaj uhol strelby: ", A.D.meno);
			scanf_s("%d", &uhol);
			souradnice(A.D.position[0][0], A.D.position[0][1], uhol, VELOCITY, Map, A, pocethracu);
			printMap(Map);
			loadToDef(DefMap, Map);
		}
		if (A.E.life == 1) {
			printf("%s, zadaj uhol strelby: ", A.E.meno);
			scanf_s("%d", &uhol);
			souradnice(A.E.position[0][0], A.E.position[0][1], uhol, VELOCITY, Map, A, pocethracu);
			printMap(Map);
			loadToDef(DefMap, Map);

		}
	}
}



int main() {
	srand(time(NULL));
	nadpis();
	mapChoice(vybermapy);
	loadMap(Map);
	playersDeclaration();
	gameCycle();
	/*printMap(Map);
	printMap(Map);
	souradnice(A.A.position[0][0],A.A.position[0][1] , 60, 11, Map, A, pocethracu);
	printMap(Map);*/
}
