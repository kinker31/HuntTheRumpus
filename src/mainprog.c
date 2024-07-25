#include "menulib.h"
#include "mazelib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

void StartGame()
{
    
}

int main()
{
    initscr(); noecho();
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
        printw("%c\n", selection);
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
                StartGame();
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