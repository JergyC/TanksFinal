#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

#pragma once


#define MAX_X 100
#define MAX_Y 20
#define MAX_PLAYERS 5

typedef struct Player {
    char meno[31];
    char tank;
    int position[2][2];
    int life = 1;
}player;
typedef struct Players {
    Player A;
    Player B;
    Player C;
    Player D; 
    Player E;
}players;




void souradnice(int Ref_x, int Ref_y, int uhel, int rychlost, char pole[MAX_Y][MAX_X]);
void nadpis();
void mapChoice(int mapNumber);
void loadMap(char Map[MAX_Y][MAX_X]);
void addPlayersToMap(char player, char Map[MAX_Y][MAX_X], int playersPositions[MAX_PLAYERS][2]);
void printMap(char Map[MAX_Y][MAX_X]);
void destroyPlayer(int x, int y, char Map[MAX_Y][MAX_X]);




