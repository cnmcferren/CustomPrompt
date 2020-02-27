#CustomPrompt

CustomPrompt is a script that gives colorful and useful bash prompts
for Linux and Mac OS X by using C++ and ANSI escape sequences.

##Installation

Download this repository. In the root of the project folder, use the 
Makefile to install.
`make install`
To update the prompt to reflect color changes, run the following command:
`make update`

##Changing Color Schemes

In the `colors.h` file, edit the variables indicated. Replace the variables
with strings of the ANSI color desired and run `make update`. To view all 
available ANSI colors, view the `ANSI.png` file in the root of the project.
