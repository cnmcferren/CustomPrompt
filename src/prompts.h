#ifndef __PROMPTS_H_INCLUDE__
#define __PROMPTS_H_INCLUDE__

#include <string> 

using namespace std;

void PrintStandard(string, string, string, int);
void Standard(int);
void PrintGit(string, string, string, int);
void Git(int, char *);
void PrintError(string, string, string, int);
void Error(int);
string FormatCWD(char *);

#endif
