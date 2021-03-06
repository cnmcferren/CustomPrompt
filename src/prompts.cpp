#include "prompts.h"
#include <sys/ioctl.h>

void PrintStandard(string cwd, string hostname, string username, int colors) {
  bool color;
  if (colors == 1) {
    color = true;
  }
  else {
    color = false;
  }
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

void PrintGit(string cwd, string hostname, string username, int colors) {
  bool color;
  if (colors == 1) {
    color = true;
  }
  else {
    color = false;
  }
  cout << (color ? GIT1  : "") << username <<
          (color ? GIT2 : "") << ARROW << " " <<
          (color ? GIT2 : "") << BRANCH << " " << hostname <<
          (color ? GIT1 : "") << ARROW << " " <<
          (color ? GIT1  : "") << cwd << (colors ? GIT3 : "") <<
          ARROW << (color ? RESET : "") << endl;

}

void Git(int colors, char * branchName) {
  int buffersize = 256;
	char cwd[buffersize];
	struct passwd* pw;

	pw = getpwuid(getuid());
	getcwd(cwd,sizeof(cwd));
	string stringHostname(branchName);

	string stringCwd = FormatCWD(cwd);
	string stringUsername = pw->pw_name;

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
  cout << (color ? ERR1  : "") << username <<
          (color ? ERR2 : "") << ARROW << " " <<
          (color ? ERR2 : "") << hostname <<
          (color ? ERR1 : "") << ARROW << " " <<
          (color ? ERR1  : "") << cwd << (colors ? ERR3 : "") <<
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
