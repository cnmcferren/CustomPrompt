#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string>
#include <iostream>

#define ARROW ""
#define DGRAYORANGE "\033[48;5;202;38;5;243m"
#define ORANGEDGRAY "\033[38;5;202;48;5;243m"
#define DGRAYDEFAULT "\033[38;5;243;48;5;234m"
#define WHITEDGRAY "\033[38;5;255;48;5;243m"
#define WHITEORANGE "\033[38;5;255;48;5;202m"
#define RESET "\033[0m"
#define BLINK "\033[5m"

using namespace std;

void PrintStandard(string, string, string, bool);
string FormatCWD(char *);

int main(int argc, char ** argv) {
	bool colors;

	if (argc>1) {
		colors = true;
	}
	else {
		colors = false;
	}	
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

void PrintStandard(string cwd, string hostname, string username, bool colors){
    cout << (colors ? WHITEDGRAY  : "") << username <<
            (colors ? DGRAYORANGE : "") << ARROW << " " <<
            (colors ? WHITEORANGE : "") << hostname <<
            (colors ? ORANGEDGRAY : "") << ARROW << " " <<
            (colors ? WHITEDGRAY  : "") << cwd << (colors ? DGRAYDEFAULT : "") <<
            ARROW << (colors ? RESET : "") << endl;
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
