#include "prompts.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <stdbool.h>

#define ARROW ""
#define BRANCH ""
#define DGRAYORANGE "\033[48;5;202;38;5;243m"
#define ORANGEDGRAY "\033[38;5;202;48;5;243m"
#define DGRAYDEFAULT "\033[38;5;243;48;5;234m"
#define WHITEDGRAY "\033[38;5;255;48;5;243m"
#define WHITEORANGE "\033[38;5;255;48;5;202m"
#define FBBW "\033[38;5;232;48;5;15m"
#define FWBR "\033[38;5;15;48;5;196m"
#define FRBW "\033[38;5;196;48;5;15m"
#define FWBD "\033[38;5;15;48;5;234m"
#define FGBB "\033[38;5;46;48;5;33m"
#define FBBG "\033[38;5;33;48;5;46m"
#define FGBB "\033[38;5;46;48;5;33m"
#define FBBD "\033[38;5;33;48;5;234m"
#define RESET "\033[0m"
#define BLINK "\033[5m"

using namespace std;

void PrintStandard(string cwd, string hostname, string username, int colors) {
  bool color;
  if (colors == 1) {
    color = true;
  }
  else {
    color = false;
  }
  cout << (color ? WHITEDGRAY  : "") << username <<
          (color ? DGRAYORANGE : "") << ARROW << " " <<
          (color ? WHITEORANGE : "") << hostname <<
          (color ? ORANGEDGRAY : "") << ARROW << " " <<
          (color ? WHITEDGRAY  : "") << cwd << (colors ? DGRAYDEFAULT : "") <<
          ARROW << (color ? RESET : "") << endl;
}

void Standard(int colors) {
  int buffersize = 256;
	char hostname[buffersize];
	char cwd[buffersize];
	struct passwd* pw;

	gethostname(hostname,sizeof(hostname));
	pw = getpwuid(getuid());
	getcwd(cwd,sizeof(cwd));

	string stringCwd = FormatCWD(cwd);
	string stringUsername = pw->pw_name;
	string stringHostname = hostname;

	if (stringCwd == stringUsername) {
		stringCwd = "~";
	}
  PrintStandard(stringCwd, stringHostname, stringUsername, colors);

}

void PrintGit(string cwd, string hostname, string username, int colors) {
  bool color;
  if (colors == 1) {
    color = true;
  }
  else {
    color = false;
  }
  cout << (color ? FGBB  : "") << username <<
          (color ? FBBG : "") << ARROW << " " <<
          (color ? FBBG : "") << BRANCH << " " << hostname <<
          (color ? FGBB : "") << ARROW << " " <<
          (color ? FGBB  : "") << cwd << (colors ? FBBD : "") <<
          ARROW << (color ? RESET : "") << endl;
}

void Git(int colors, char * branchName) {
  int buffersize = 256;
	//char hostname[buffersize];
	char cwd[buffersize];
	struct passwd* pw;

	//gethostname(hostname,sizeof(hostname));
	pw = getpwuid(getuid());
	getcwd(cwd,sizeof(cwd));
	string stringHostname(branchName);

	string stringCwd = FormatCWD(cwd);
	string stringUsername = pw->pw_name;
	//string stringHostname = hostname;

	if (stringCwd == stringUsername) {
		stringCwd = "~";
	}

  PrintGit(stringCwd, stringHostname, stringUsername, colors);

}

void PrintError(string cwd, string hostname, string username, int colors) {
  bool color;
  if (colors == 1) {
    color = true;
  }
  else {
    color = false;
  }
  cout << (color ? FRBW  : "") << username <<
          (color ? FWBR : "") << ARROW << " " <<
          (color ? FWBR : "") << hostname <<
          (color ? FRBW : "") << ARROW << " " <<
          (color ? FRBW  : "") << cwd << (colors ? FWBD : "") <<
          ARROW << (color ? RESET : "") << endl;
}

void Error(int colors) {
  int buffersize = 256;
	char hostname[buffersize];
	char cwd[buffersize];
	struct passwd* pw;

	gethostname(hostname,sizeof(hostname));
	pw = getpwuid(getuid());
	getcwd(cwd,sizeof(cwd));

	string stringCwd = FormatCWD(cwd);
	string stringUsername = pw->pw_name;
	string stringHostname = hostname;

	if (stringCwd == stringUsername) {
		stringCwd = "~";
	}

  PrintError(stringCwd, stringHostname, stringUsername, colors);
}

string FormatCWD(char * cwd) {
  string stringCwd = cwd;

  int size = stringCwd.length();
  int slashCount = 0;
  int slashIndex = 0;
  for (int i=0; i<size; i++) {
      if (stringCwd.at(i) == '/') {
          slashIndex = i;
          slashCount++;
      }
  }

  string outputCwd = "";
  if (slashIndex != 0) {
      for (int i=slashIndex+1; i<size; i++) {
          outputCwd += stringCwd.at(i);
      }
  }

  return outputCwd;
}
