#include "Tanks.h"
#pragma warning(disable : 4996)


int i, y = 0, x = 0;


FILE* fr;




void souradnice(int Ref_x, int Ref_y, int uhel, int rychlost, char pole[MAX_Y][MAX_X], Players A, int *pocetHracu)
{
    players* pa;
    pa = &A;
    float g = 9.81; //tihove zrychleni
    int i;
    if (uhel > 90)
    {
        i = -1;
    }
    else
    {
        i = 1;
    }
    int dopad = 0;
    int Vysl_x;
    int Vysl_y;
    int x;
    int y;
    double a; //clen souradnice y
    double b; // clen souradnice y
    double c; // souradnice y pred zaokrouhlenim

    do
    {
        x = Ref_x + i;
        a = i * tan(uhel * (M_PI / 180));
        b = 0.5 * g * pow(i / (rychlost * cos(uhel * (M_PI / 180))), 2);
        c = (Ref_y - (a - b) + 0.5);
        y = (int)c;
        if (uhel > 90)
        {
            i--;
        }
        else
        {
            i++;
        }
        if (y <= 0) {
            y = 0;
        }
        else if (y >= MAX_Y) {
            break;
        }
        if (x >= MAX_X || x <= 0) {
            break;
        }
        dopad_str(uhel, pole, x, y, &x, &y);
        if (pole[y][x] == '*') //dopad na zem
        {
            Vysl_x = x;
            Vysl_y = y;
            dopad = 1;
            destroyTerrain(x, y, pole);
        }
        else if (pole[y][x] >= 65 && pole[y][x] <= 69) // sestreleni tanku (v podstate i sebe sama pri zadani uhlu 90)
        {
            Vysl_x = x;
            Vysl_y = y;
            dopad = 1;
            destroyPlayer(x, y, pocetHracu, pole, pa);
        }
        else
        {
            pole[y][x] = '.';

            if (uhel > 90)
            {
                i--;
            }
            else
            {
                i++;
            }

        }
    } while (!dopad);
}

void countersouradnice(int Ref_x, int Ref_y, int uhel, int rychlost, char pole[MAX_Y][MAX_X])
{
    float g = 9.81; //tihove zrychleni
    int i;
    if (uhel > 90)
    {
        i = -1;
    }
    else
    {
        i = 1;
    }
    int dopad = 0;
    int Vysl_x;
    int Vysl_y;
    int x;
    int y;
    double a; //clen souradnice y
    double b; // clen souradnice y
    double c; // souradnice y pred zaokrouhlenim

    do
    {
        x = Ref_x + i;
        a = i * tan(uhel * (M_PI / 180));
        b = 0.5 * g * pow(i / (rychlost * cos(uhel * (M_PI / 180))), 2);
        c = (Ref_y - (a - b) + 0.5);
        y = (int)c;
        if (uhel > 90)
        {
            i--;
        }
        else
        {
            i++;
        }
        if (y <= 0) {
            y = 0;
        }
        else if (y >= MAX_Y) {
            break;
        }
        if (x >= MAX_X || x <= 0) {
            break;
        }
        dopad_str(uhel, pole, x, y, &x, &y);
        if (pole[y][x] == '*') //dopad na zem
        {
            Vysl_x = x;
            Vysl_y = y;
            dopad = 1;
        }
        else
        {
            pole[y][x] = ' ';

            if (uhel > 90)
            {
                i--;
            }
            else
            {
                i++;
            }

        }
    } while (!dopad);
}

void nadpis()
{
	printf_s("\n                  __________        ____       ___     ___     ___    __     ___     ___");
	printf_s("\n                 |___   ___|       /    \\      |  \\   |  |    |  |  /  /     \\  \\   /  /");
	printf_s("\n                     |  |         /  /\\  \\     |   \\  |  |    |  | /  /       \\  \\ /  / ");
	printf_s("\n                     |  |        /  /__\\  \\    |    \\ |  |    |  |/  /         \\     /");
	printf_s("\n                     |  |       /   ____   \\   |  |\\ \\|  |    |  |\\  \\          |   |");
	printf_s("\n                     |__|      /__/      \\__\\  |__| \\____|    |__| \\__\\         |___|");
	printf_s("\n");

}
void mapChoice(int vybermapy) {
    system("cls");
    nadpis();
    printf_s("\nVitejte ve hre tanky!");
    printf_s("\nMate moznost vybrat si z peti hernich map.\n");
b:
    printf_s("Zadejte prosim cislo mapy (1-5): ");
    scanf_s("%d", &vybermapy);
    if (vybermapy > 5 || vybermapy < 1)
    {
        printf_s("Neplatna volba!\n");
        goto b;
    }
	switch (vybermapy)
	{
	case 1:
		fr = fopen("Map1.txt", "r");
		break;
	case 2:
		fr = fopen("Map2.txt", "r");
		break;
	case 3:
		fr = fopen("Map3.txt", "r");
		break;
	case 4:
		fr = fopen("Map4.txt", "r");
		break;
	case 5:
		fr = fopen("Map5.txt", "r");
		break;
	}
}//opens File with map;
void loadMap(char Map[MAX_Y][MAX_X]) {
	for (y = 0; y < MAX_Y; y++) {
		for (x = 0; x < MAX_X; x++) {
			Map[y][x] = getc(fr);
			if (Map[y][x] == '\n') {
				break;
			}
		}
	}
	fclose(fr);
}
void addPlayersToMap(char player, char Map[MAX_Y][MAX_X], int playersPositions[2][2]) {
    int x;
    x = rand() % 50;
    for (y = 0; y < MAX_Y; y++) {
        if (Map[y][x] >= 65 && Map[y][x] <= 69) {
            x = rand() % 50;
        }
        else if (Map[y][x] == '*') {
            Map[y - 1][x] = player;
            break;
        }
    }
    playersPositions[0][0] = x; //xova suradnica hraca
    playersPositions[0][1] = y - 1;
    
 }
void loadToDef(char Map[MAX_Y][MAX_X], char Def[MAX_Y][MAX_X])
{
    for (y = 0; y < MAX_Y; y++) {
        for (x = 0; x < MAX_X; x++) {
            Def[y][x] = Map[y][x];
        }
    }
}
void printMap(char Map[MAX_Y][MAX_X]) {
    system("cls");
	for (y = 0; y < MAX_Y; y++) {
		for (x = 0; x < MAX_X; x++) {
			printf("%c", Map[y][x]);
		}
		printf("\n");
	}
}
void destroyPlayer(int a, int b,  int *pocetHracu, char Map[MAX_Y][MAX_X], struct Players *A) {

    switch (Map[b][a]) {
            case 'A':
                A->A.life = 0;
                break;
            case 'B':
                A->B.life = 0;
                break;
            case 'C':
                A->C.life = 0;
                break;
            case 'D':
                A->D.life = 0;
                break;
            case 'E':
                A->E.life = 0;
                break;
        }
        Map[b][a] = '\0';
        *pocetHracu = *pocetHracu - 1;

}
void destroyTerrain(int a, int b, char Map[MAX_Y][MAX_X]) {
        Map[b][a] = ' ';
}//vymysliet algoritmus
void win() {
    system("cls");
    printf("Koniec hry. \nDufame, ze ste si nasu hru uzili. \nGratulujeme vitazovi\n\n\n\n\n");
}
void dopad_str(int uhel, char pole[MAX_Y][MAX_X], int dopadX, int dopadY, int* povrchX, int* povrchY)
{
    int i = 1;
    int x = dopadX;
    int y = dopadY;
    //int* povrchX = 0, * povrchY = 0;

    if (uhel <= 45)
    {
        while (pole[y - 1][x - 1] != ' ')
        {
            x--;
            y--;
        }
        *povrchX = x;
        *povrchY = y;
    }
    else if (uhel > 45 && uhel < 90)
    {
        while (pole[y - 1][x - 1] != ' ')
        {
            y--;
            if (i % 2 != 0)
            {
                x--;
            }
            i++;
        }
        *povrchX = x;
        *povrchY = y;
    }
    else if (uhel > 90 && uhel < 135)
    {
        while (pole[y + 1][x - 1] != ' ')
        {
            y--;
            if (i % 2 != 0)
            {
                x++;
            }
            i++;
        }
        *povrchX = x;
        *povrchY = y;
    }
    else
    {
        while (pole[y + 1][x - 1] != ' ')
        {
            x++;
            y--;
        }
        *povrchX = x;
        *povrchY = y;
    }
}