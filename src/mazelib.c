#include "mazelib.h"
#include <stdlib.h>
#include <ncurses.h>

#define IF_GOOD_TILE    if(ValidTile(maze, posTemp))
#define SET_ENTPOS      ent->position = posTemp;
#define ENT_CHECK       IF_GOOD_TILE {SET_ENTPOS}
#define SET_PPOS        p->prop.position = posTemp;
#define P_CHECK         IF_GOOD_TILE {SET_PPOS}
#define TPOINT          point posTemp

char GetCell(char * maze[], point p2d)
{ return maze[p2d.x][p2d.y]; }

//Assume standard of n|e|w|s

void MoveEnt(struct ent2d *ent, char *maze[])
{
    unsigned short int randVal = (rand() % 4) + 1;
    TPOINT = ent->position;
    switch(randVal)
    {
        case 1:
            posTemp.y += 1;
            ENT_CHECK
            break;
        case 2:
            posTemp.x += 1;
            ENT_CHECK
            break;
        case 3:
            posTemp.x -= 1;
            ENT_CHECK
            break;
        case 4:
            posTemp.y -= 1;
            ENT_CHECK
            break;
        default:
            break;
    }
}

void MovePlayer(struct player *p, char dir, char *maze[])
{
    TPOINT = p->prop.position;
    switch(dir)
    {
        case 'n':
            posTemp.y += 1;
            P_CHECK
            break;
        case 'e':
            posTemp.x += 1;
            P_CHECK
            break;
        case 'w':
            posTemp.x -= 1;
            P_CHECK
            break;
        case 's':
            posTemp.y -= 1;
            P_CHECK
            break;
        default:
            break;
    }
    BumpLogic(p, maze);
    ScanArea(p, maze);
}

void GetMaxAmounts(unsigned short int x, unsigned short int y, unsigned short int *p, unsigned short int *c, unsigned short int *t)
{
    unsigned int maxVal = x * y;
    *p = maxVal / 6;
    *t = maxVal / 12;
    *c = maxVal / 24;
}

char RandTile(unsigned short int *p, unsigned short int *c, unsigned short int *t)
{
    int randVal = rand() % 128;
    if(randVal < 64) {return ' ';}
    else if(randVal >= 64 && randVal < 96) {return '#';}
    else
    {
        randVal = (rand() % 4) + 1;
        switch(randVal)
        {
        case 1: 
        case 2:
            if(*p > 0) {*p -= 1; return 'p';}
        case 3:
            if(*t > 0) {*t -= 1; return 't';}
        case 4:
            if(*c > 0) {*c -= 1; return 'c';}
        default:
            return ' ';
        }          
    }
}

void InitMaze(char *maze[], unsigned short int x, unsigned short int y)
{
    short unsigned int i, j, pitTotal, corpseTotal, teleTotal;
    GetMaxAmounts(x, y, &pitTotal, &corpseTotal, &teleTotal);
    for(i = 0; i < x; i++)
    { maze[i] = (char*)malloc(y); }
    for(i = 0; i < x; i++)
    {
        for(j = 0; j < y; j++)
        {
            if(i == 0 || i == (x - 1) || j == 0 || j == (y - 1))
            {maze[i][j] = '#'; continue;}
        }
    }
}

void LoadMaze(char *maze[])
{} //temp an empty useless function, add this later

bool ValidTile(char *maze[], point coord)
{
    bool result = false;
    if(GetCell(maze, coord) != '#')
    {result = true;}
    return result;
}

void Ent2DFunc(char *maze[], struct ent2d *ents, point maxes, unsigned short int maxAmount, char type)
{
    ents = malloc(sizeof(struct ent2d) * maxAmount);
    point coordinate;
    for(unsigned short int i = 0; i < maxAmount; i++)
    {
        ents[i].property = type;
        do{coordinate.x = rand() % maxes.x; coordinate.y = rand() % maxes.y;}
        while(ValidTile(maze, coordinate));
        ents[i].position = coordinate;
    }
}

void PitMercyFunc(player_s, maze_s)
{
    //implement soon-ish
}

void DennisFunc(player_s, maze_s)
{
    //implement soon-ish
}

void FoundTeleporter(player_s, short int xMax, short int yMax)
{
    //implement soon-ish
}

void FoundRumpus()
{
    //implement soon-ish
}

void CheckEnts(point)
{
    //implement soon-ish
}

void FoundRonpis()
{
    //implement soon-ish
}

void GunLogic(player_s, maze_s)
{
    //implement soon-ish
}

void FoundCorpse(player_s)
{
    //implement soon-ish
}

void FoundPit(player_s)
{
    //implement soon-ish
}

void ScanArea(struct player *p, char *maze[])
{
    TPOINT = p->prop.position;
    //implement function later
}

void BumpLogic(struct player *p, char *maze[])
{
    TPOINT = p->prop.position;
    char tileLogic = GetCell(maze, posTemp);
}