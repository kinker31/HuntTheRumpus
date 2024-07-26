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

struct ent2d
{
    short unsigned int x, y;
    char property;
};

struct player
{
    struct ent2d prop;
    unsigned short int ammo;
    bool dennis;
    unsigned short int pitMercies;
};

void MoveEnt(struct ent2d *ent, char *maze[]);
void MovePlayer(struct player *p, char dir, char *maze[]);
void InitMaze(char *maze[], unsigned short int x, unsigned short int y);
void LoadMaze(char *maze[]);
void InitPlayer(struct player *p, unsigned short int *op)
{
    p->prop.x = 1;
    p->prop.y = 1;
    p->prop.property = 'y';
    p->ammo = 3;
    p->dennis = true;
    p->pitMercies = 0;
}
void RumpusFunc(char *maze[]);
void RonpisFunc(char *maze[]);
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