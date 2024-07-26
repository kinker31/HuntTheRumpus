#pragma once
#include <stdbool.h>

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
char GetCell(char *maze[], struct point2d p2d);
void MoveEnt(struct ent2d *ent, char *maze[]);
void MovePlayer(struct player *p, char dir, char *maze[]);
char RandTile(unsigned short int *p, unsigned short int *c, unsigned short int *t);
void GetMaxAmounts(unsigned short int x, unsigned short int y, unsigned short int *p, unsigned short int *c, unsigned short int *t);
void InitMaze(char *maze[], unsigned short int x, unsigned short int y);

void LoadMaze(char *maze[]);
void InitPlayer(struct player *p, unsigned short int *op)
{
    p->prop.position.x = 1;
    p->prop.position.y = 1;
    p->prop.property = 'y';
    p->ammo = 3;
    p->dennis = true;
    p->pitMercies = 0;
}
bool ValidTile(char *maze[], struct point2d coord);
void Ent2DFunc(char *maze[], struct ent2d *ents, struct point2d maxes, unsigned short int maxAmount, char type);
void PitMercyFunc(struct player *p, char *maze[]);
void ExtraDennisFunc(struct player *p, char *maze[]);
void ScanArea(struct player *p, char *maze[]);
void BumpLogic(struct player *p, char *maze[]);
void FoundTeleporter(struct player *p, short int xMax, short int yMax);
void FoundRumpus();
void FoundRonpis();
void GunLogic(struct player *p, char dir, char *maze[]);
void FoundCorpse(struct player *p);
void FoundPit(struct player *p);
