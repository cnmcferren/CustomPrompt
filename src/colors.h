#ifndef __COLORS_H_INCLUDE__
#define __COLORS_H_INCLUDE__

//Shapes
#define ARROW ""
#define BRANCH ""

//Colors
//To change colors, change values here but choosing appropriate
//ANSI color
#define STANDPRIM "202" //Orange
#define STANDSEC "243" //DarkGray
#define STANDTER "255" //White
#define GITPRIM "46" //Blue
#define GITSEC "33" //Green
#define ERRPRIM "196" //White
#define ERRSEC "255" //Red

//Standard Prompt Colors
#define STAND1 "\033[38;5;" STANDTER ";48;5;" STANDSEC "m"
#define STAND2 "\033[38;5;" STANDSEC ";48;5;" STANDPRIM "m"
#define STAND3 "\033[38;5;" STANDTER ";48;5;" STANDPRIM "m"
#define STAND4 "\033[38;5;" STANDPRIM ";48;5;" STANDSEC "m"
#define STAND5 "\033[38;5;" STANDSEC ";48;5;234m"

//Git Prompt Colors
#define GIT1 "\033[38;5;" GITPRIM ";48;5;" GITSEC "m"
#define GIT2 "\033[38;5;" GITSEC ";48;5;" GITPRIM "m"
#define GIT3 "\033[38;5;" GITSEC ";48;5;234m"

//Error Prompt Colors
#define ERR1 "\033[38;5;" ERRPRIM ";48;5;" ERRSEC "m"
#define ERR2 "\033[38;5;" ERRSEC ";48;5;" ERRPRIM "m"
#define ERR3 "\033[38;5;" ERRSEC ";48;5;234m"

//Modes
#define RESET "\033[0m"

#endif
