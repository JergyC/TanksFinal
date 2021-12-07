#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

#pragma once


#define MAX_X 200
#define MAX_Y 50
#define MAX_PLAYERS 5
#define MAX_VEL 40

typedef struct Player {
    char meno[31];
    char tank;
    int position[2][2];
    int life = 0;
}player;
typedef struct Players {
    Player A;
    Player B;
    Player C;
    Player D; 
    Player E;
}players;




void souradnice(int Ref_x, int Ref_y, int uhel, int rychlost, char pole[MAX_Y][MAX_X], Players A, int *pocetHracu);
void nadpis();
void mapChoice(int mapNumber);
void loadMap(char Map[MAX_Y][MAX_X]);
void addPlayersToMap(char player, char Map[MAX_Y][MAX_X], int playersPositions[2][2]);
void loadToDef(char Map[MAX_Y][MAX_X], char Def[MAX_Y][MAX_X]);
void printMap(char Map[MAX_Y][MAX_X]);
void destroyPlayer(int x, int y, int *pocetHracu, char Map[MAX_Y][MAX_X], Players A);
void destroyTerrain(int a, int b, char Map[MAX_Y][MAX_X]);
void win();




