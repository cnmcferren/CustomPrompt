#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <string>
#include <iostream>

#define ARROW ""
#define BRANCH ""
#define RESET "\033[0m"
#define BLINK "\033[5m"
#define FGBB "\033[38;5;46;48;5;33m"
#define FBBG "\033[38;5;33;48;5;46m"
#define FGBB "\033[38;5;46;48;5;33m"
#define FBBD "\033[38;5;33;48;5;234m"

using namespace std;

void PrintStandard(string, string, string, bool);
string FormatCWD(char *);

int main(int argc, char ** argv) {
	bool colors;

	if (argc>2) {
		colors = true;
	}
	else {
		colors = false;
	}	
	int buffersize = 256;
	//char hostname[buffersize];
	char cwd[buffersize];
	struct passwd* pw;

	//gethostname(hostname,sizeof(hostname));
	pw = getpwuid(getuid());
	getcwd(cwd,sizeof(cwd));
	string stringHostname(argv[1]);

	string stringCwd = FormatCWD(cwd);
	string stringUsername = pw->pw_name;
	//string stringHostname = hostname;

	if (stringCwd == stringUsername) {
		stringCwd = "~";
	}

	PrintStandard(stringCwd, stringHostname, stringUsername, colors);

}

void PrintStandard(string cwd, string hostname, string username, bool colors){
    cout << (colors ? FGBB  : "") << username <<
            (colors ? FBBG : "") << ARROW << " " <<
            (colors ? FBBG : "") << BRANCH << " " << hostname <<
            (colors ? FGBB : "") << ARROW << " " <<
            (colors ? FGBB  : "") << cwd << (colors ? FBBD : "") <<
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
