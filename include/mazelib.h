#pragma once
#include <stdbool.h>

#define player_s    struct player *p
#define ent_s       struct ent2d *ent
#define maze_s      char *maze[]
#define XY_PAIR     unsigned short int x, unsigned short int y
#define point       struct point2d

/*
Char Legend
#: Wall
r: Real Deal Rumpus
f: Ronpis, a fake Rumpis
c: Corpse
t: Teleporter
p: Pit
(Space): Moveable Space
*/

struct point2d
{
    short unsigned int x, y;
};

struct ent2d
{
    struct point2d position;
    char property;
};

struct player
{
    struct ent2d prop;
    unsigned short int ammo;
    bool dennis;
    unsigned short int pitMercies;
};

char GetCell(maze_s, struct point2d p2d);
void MoveEnt(ent_s, maze_s);
void MovePlayer(player_s, char dir, maze_s);
char RandTile(unsigned short int *p, unsigned short int *c, unsigned short int *t);
void GetMaxAmounts(XY_PAIR, unsigned short int *p, unsigned short int *c, unsigned short int *t);
void InitMaze(maze_s, XY_PAIR);

void LoadMaze(maze_s);
void InitPlayer(player_s, unsigned short int *op)
{
    p->prop.position.x = 1;
    p->prop.position.y = 1;
    p->prop.property = 'y';
    p->ammo = 3;
    p->dennis = true;
    p->pitMercies = 0;
}
bool ValidTile(maze_s, struct point2d coord);
void Ent2DFunc(maze_s, ent_s, struct point2d maxes, unsigned short int maxAmount, char type);
void PitMercyFunc(player_s, maze_s);
void DennisFunc(player_s, maze_s);
void FoundTeleporter(player_s, short int xMax, short int yMax);
void FoundRumpus();
void FoundRonpis();
void GunLogic(player_s, maze_s);
void FoundCorpse(player_s);
void FoundPit(player_s);
void CheckEnts(point);
void ScanArea(player_s, maze_s);
void BumpLogic(player_s, maze_s);