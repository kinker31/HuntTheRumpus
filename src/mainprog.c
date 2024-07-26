#include "menulib.h"
#include "mazelib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

void MainGameLoop(unsigned short int *op, char *maze[])
{
    bool gameOver = false;
    struct player itsYou; InitPlayer(&itsYou, op);
    RumpusFunc(maze); RonpisFunc(maze);
    while(!gameOver)
    {
        clear();
    }
}

//Sizes must be bigger than 1 for a map of the proper size to generate; The borders of the matrix is surrounded by wall

void CustomSizeCrap(unsigned short int *x, unsigned short int *y)
{

}

void StartGame(bool customMap, unsigned short int *op)
{
    char*** mazeMatrix;
    unsigned short int i, j;
    //TODO: Find good way of storing and loading map files
    if(customMap)
    { printw("CUSTOM MAP FUNCTIONALITY NOT IMPLEMENTED YET\n\n"); }
    printw("Want a [S]mall, [M]edium, or [L]arge map? [C]ustom size also supported as well: "); refresh();
    char pick = getch(); printw("\n");
    switch(pick)
    {
        case 's':
            i = 9, j = 9;
            break;
        case 'm':
            i = 17, j = 17;
            break;
        case 'l':
            i = 25, j = 25;
            break;
        case 'c':
            //CustomSizeCrap(&i, &j);
            printw("TODO: Do this crap later.\n");
            i = 129, j = 129;
            break;
        default:
            printw("Invalid selection, defaulting to [m]edium...\n");
            i = 16, j = 16;
            break;
    }
    InitMaze(mazeMatrix, i, j);
    MainGameLoop(op, mazeMatrix);
}

int main()
{
    initscr();
    printw("Welcome to Hunt the Rumpus!\n"); refresh();
    sleep(1);
    InitDirectory();
    char selection;
    unsigned short int options;
    while(selection != 'q')
    {
        clear();
        printw("Make a selection, or press h for help: "); refresh();
        selection = getch();
        printw("\n");
        switch(selection)
        {
            case 'h':
                PrintCommands();
                break;
            case 'q':
                printw("Well, it's been fun, see you next time!\n"); refresh();
                sleep(1);
            case 'o':
                OptionsScreen(&options);
                break;
            case 'n':
                StartGame(false, &options);
                break;
            default:
                printw("Actual value, please.\n"); refresh();
                sleep(1);
                break;
        }
    }
    endwin();
    return 0;
}