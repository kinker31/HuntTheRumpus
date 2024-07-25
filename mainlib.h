#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <curses.h>

void PrintCommands()
{
    printw("[H]elp: Prints this screen.\n");
    printw("[O]ptions: Opens up the options, which has a menu of it's own.\n");
    printw("[N]ew Game: \n");
    printw("[C]ustom Maze: \n");
    printw("Please use lowercase keys when selecting, and this menu might change in the future!\n");
    printw("Press any key to continue.\n");
    char dummyValue = getch();
}