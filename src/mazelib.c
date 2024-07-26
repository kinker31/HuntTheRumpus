#include "mazelib.h"
#include <stdlib.h>

char GetCell(char * maze[], struct point2d p2d)
{ return maze[p2d.x][p2d.y]; }


void MoveEnt(struct ent2d *ent, char *maze[])
{

}

void MovePlayer(struct player *p, char dir, char *maze[])
{

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

bool ValidTile(char *maze[], struct point2d coord)
{
    bool result = false;
    if(maze[coord.x][coord.y] != '#')
    {result = true;}
    return result;
}

void Ent2DFunc(char *maze[], struct ent2d *ents, struct point2d maxes, unsigned short int maxAmount, char type)
{
    ents = malloc(sizeof(struct ent2d) * maxAmount);
    struct point2d coordinate;
    for(unsigned short int i = 0; i < maxAmount; i++)
    {
        ents[i].property = type;
        do{coordinate.x = rand() % maxes.x; coordinate.y = rand() % maxes.y;}
        while(ValidTile(maze, coordinate));
        ents[i].position = coordinate;
    }
}