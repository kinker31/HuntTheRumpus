#pragma once

void InitDirectory();
void PrintCommands();
void SaveOptions(unsigned short int *op);
void LoadOptions(unsigned short int *op);

void ToggleOption(unsigned short int pick, unsigned short int *op)
{ unsigned short int bit = 1 << pick; *op ^= bit; }

void GetOpState(unsigned short int *op, unsigned short int pick, char *str);
void PrintOptions();
void OptionsScreen(unsigned short int *op);
void PrintGameCommands();