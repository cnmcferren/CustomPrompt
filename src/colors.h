#ifndef __COLORS_H_INCLUDE__
#define __COLORS_H_INCLUDE__

//Shapes
#define ARROW ""
#define BRANCH ""

//WHITEDGRAY DGRAYORANGE WHITEORANGE ORANGEDGRAY WHITEDGRAY DGRAYDEFAULT stand
//FGBB FBBG FBBG FGBB FGBB FBBD git
//FRBW FWBR FWBR FRBW FRBW FWBD err

#define STANDPRIM "202" //Orange
#define STANDSEC "243" //DarkGray
#define STANDTER "255" //White
#define GITPRIM "46" //Blue
#define GITSEC "33" //Green
#define ERRPRIM "255" //White
#define ERRSEC "196" //Red

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

/*
//Colors
#define DGRAYORANGE "\033[48;5;202;38;5;243m"
#define ORANGEDGRAY "\033[38;5;202;48;5;243m"
#define DGRAYDEFAULT "\033[38;5;243;48;5;234m"
#define WHITEDGRAY "\033[38;5;255;48;5;243m"
#define WHITEORANGE "\033[38;5;255;48;5;202m"
*/
#define FBBW "\033[38;5;232;48;5;15m"
#define FWBR "\033[38;5;15;48;5;196m"
#define FRBW "\033[38;5;196;48;5;15m"
#define FWBD "\033[38;5;15;48;5;234m"
#define FGBB "\033[38;5;46;48;5;33m"
#define FBBG "\033[38;5;33;48;5;46m"
#define FGBB "\033[38;5;46;48;5;33m"
#define FBBD "\033[38;5;33;48;5;234m"

//Modes
#define RESET "\033[0m"
#define BLINK "\033[5m"

#endif
