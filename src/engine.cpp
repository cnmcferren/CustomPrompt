#include "prompts.h"
#include <iostream>

using namespace std;

/*
 * argv[1] represents the prompt number (0=standard, 1=error, 2=git)
 * argv[2] represents whether colors will print or not
 * argv[3] is the branch name in a git prompt
 */
int main(int argc, char ** argv) {
	int colors = atoi(argv[2]);
	int promptNum = atoi(argv[1]);

	if (promptNum == 0) {
		Standard(colors);
	}
	else if (promptNum == 1) {
		Error(colors);
	}
	else {
		Git(colors, argv[3]);
	}

	return 0;
}
