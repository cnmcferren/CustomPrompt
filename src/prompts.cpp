#include "prompts.h"
#include "colors.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <stdbool.h>

using namespace std;


//WHITEDGRAY DGRAYORANGE WHITEORANGE ORANGEDGRAY WHITEDGRAY DGRAYDEFAULT stand
//FGBB FBBG FBBG FGBB FGBB FBBD git
//FRBW FWBR FWBR FRBW FRBW FWBD err
void PrintStandard(string cwd, string hostname, string username, int colors) {
  bool color;
  if (colors == 1) {
    color = true;
  }
  else {
    color = false;
  }
  /*
  cout << (color ? WHITEDGRAY  : "") << username <<
          (color ? DGRAYORANGE : "") << ARROW << " " <<
          (color ? WHITEORANGE : "") << hostname <<
          (color ? ORANGEDGRAY : "") << ARROW << " " <<
          (color ? WHITEDGRAY  : "") << cwd << (colors ? DGRAYDEFAULT : "") <<
          ARROW << (color ? RESET : "") << endl;
  */
  cout << (color ? STAND1  : "") << username <<
          (color ? STAND2 : "") << ARROW << " " <<
          (color ? STAND3 : "") << hostname <<
          (color ? STAND4 : "") << ARROW << " " <<
          (color ? STAND1  : "") << cwd << (colors ? STAND5 : "") <<
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

//FGBB FBBG FBBG FGBB FGBB FBBD
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

//FRBW FWBR FWBR FRBW FRBW FWBD
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
