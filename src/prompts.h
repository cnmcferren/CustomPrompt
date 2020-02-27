#ifndef __PROMPTS_H_INCLUDE__
#define __PROMPTS_H_INCLUDE__

#include "prompts.h"
#include "colors.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <stdbool.h>

using namespace std;

void PrintStandard(string, string, string, int);
void Standard(int);
void PrintGit(string, string, string, int);
void Git(int, char *);
void PrintError(string, string, string, int);
void Error(int);
string FormatCWD(char *);

#endif
